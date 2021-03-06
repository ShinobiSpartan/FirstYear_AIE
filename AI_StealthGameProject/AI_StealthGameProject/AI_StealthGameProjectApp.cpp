#include "AI_StealthGameProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include "GameObject.h"
#include "KeyboardController.h"
#include "Pursue_State.h"
#include "Wander_State.h"
#include "PathFind_State.h"


AI_StealthGameProjectApp::AI_StealthGameProjectApp() {

}

AI_StealthGameProjectApp::~AI_StealthGameProjectApp() {

}

bool AI_StealthGameProjectApp::startup() {
	
	// Sets up renderer and font use
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	// Setting up the graph
	m_graph = new Graph();
	CreateGraph();

	srand(time(nullptr));

	// Pathfinding using the A* Method
	GraphNode* startNode = m_graph->GetNodes()[740];
	GraphNode* endNode = m_graph->GetNodes()[rand() % 760 + 1];

	m_targetPath = m_graph->aStarSearch(startNode, endNode);

	for (auto node : m_targetPath)
	{
		node->isHighlighted = true;
	}
	
	// Creates player object and adds Keyboard Controller to it
	GameObject* m_player = new GameObject(new aie::Texture("../bin/textures/Player_Knife.png"), Vector2(100, 360), Player);
	m_gameObjects.push_back(m_player);
	m_player->AddBehaviour(new KeyboardController(aie::Input::getInstance()));
	
	// Creates series of 'dumb' enemies which wander until radii has been entered and then enters pursue state
	for (int i = 0; i < 30; i++)
	{
		GameObject* newDumbEnemy = new GameObject(new aie::Texture("../bin/textures/Enemy_Sprite.png"), Vector2(1300, 360), Alien);
		m_gameObjects.push_back(newDumbEnemy);
		m_finiteStateMachine = new StateMachine();
		m_finiteStateMachine->ChangeState(newDumbEnemy, new Wander_State(m_player, -5.0f, 20.0f, 1.0f));
		newDumbEnemy->AddBehaviour(m_finiteStateMachine);
	}

	// Creates 'smart' ai which follows an A* path created to a random point
	GameObject* newSmartEnemy = new GameObject(new aie::Texture("../bin/textures/SmartEnemy_Sprite.png"), Vector2(1225, 55), S_Alien);
	m_gameObjects.push_back(newSmartEnemy);
	m_finiteStateMachine = new StateMachine();
	m_finiteStateMachine->ChangeState(newSmartEnemy, new PathFind_State(m_targetPath, m_graph));
	newSmartEnemy->AddBehaviour(m_finiteStateMachine);

	return true;
}

void AI_StealthGameProjectApp::shutdown() {

	// Deletes all of the variables
	for (auto gameObject : m_gameObjects)
		delete gameObject;
	delete m_font;
	delete m_2dRenderer;
	delete m_graph;
}

void AI_StealthGameProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	srand(time(nullptr));

	// Updates all game objects
	for (auto gameObjects : m_gameObjects)
		gameObjects->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AI_StealthGameProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// Changes the background colour of the window
	m_Application->setBackgroundColour(1, 1, 1, 1);

	// draw your stuff here!
	for (auto gameObject : m_gameObjects)
		gameObject->draw(m_2dRenderer);

	// draw your graph
	m_graph->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	//m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}

void AI_StealthGameProjectApp::CreateGraph()
{
	// Sets up the nodes on the x axis
	for (int x = 0; x < 38; ++x)
	{
		// Sets up the nodes on the y axis
		for (int y = 0; y < 20; ++y)
		{
			// Generates all of the nodes
			GraphNode* node = new GraphNode();
			node->SetPosition(Vector2(46 + x * 32, 55 + y * 32));
			m_graph->AddNode(node);
		}
	}

	// Generates all of the connections between the nodes
	for (auto nodeA : m_graph->GetNodes())
	{
		for (auto nodeB : m_graph->GetNodes())
		{
			if (nodeA == nodeB)
				continue;

			Vector2 dist = nodeB->GetPosition() - nodeA->GetPosition();
			float length = dist.magnitude();
			if (length <= 50.f)
				m_graph->ConnectNode(nodeA, nodeB, length);
		}
	}
}
