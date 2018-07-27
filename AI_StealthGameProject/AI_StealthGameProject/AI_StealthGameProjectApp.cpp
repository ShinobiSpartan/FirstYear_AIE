#include "AI_StealthGameProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameObject.h"
#include "KeyboardController.h"
#include "StateMachine.h"
#include "Pursue_State.h"
#include "Wander_State.h"
#include "Graph.h"


AI_StealthGameProjectApp::AI_StealthGameProjectApp() {

}

AI_StealthGameProjectApp::~AI_StealthGameProjectApp() {

}

bool AI_StealthGameProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	// Setting up the graph
	m_graph = new Graph();
	CreateGraph();

	// Pathfinding using the A* Method
	GraphNode* startNode = m_graph->GetNodes()[740];
	GraphNode* endNode = m_graph->GetNodes()[169];

	std::vector<GraphNode*> path = m_graph->aStarSearch(startNode, endNode);

	for (auto node : path)
	{
		node->isHighlighted = true;
	}
	

	GameObject* m_player = new GameObject(new aie::Texture("../bin/textures/Player_Knife.png"), Vector2(100, 360), Player);
	
	m_gameObjects.push_back(m_player);
	m_player->AddBehaviour(new KeyboardController(aie::Input::getInstance()));
	

	
	
	for (int i = 0; i < 40; i++)
	{
		GameObject* newDumbEnemy = new GameObject(new aie::Texture("../bin/textures/Enemy_Sprite.png"), Vector2(1300, 360), Alien);
		m_gameObjects.push_back(newDumbEnemy);
		m_finiteStateMachine = new StateMachine();
		m_finiteStateMachine->ChangeState(newDumbEnemy, new Wander_State(m_player, -5.0f, 20.0f, 1.0f));
		newDumbEnemy->AddBehaviour(m_finiteStateMachine);
	}

	return true;
}

void AI_StealthGameProjectApp::shutdown() {

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
	for (int x = 0; x < 38; ++x)
	{
		for (int y = 0; y < 20; ++y)
		{
			GraphNode* node = new GraphNode();
			node->SetPosition(Vector2(46 + x * 32, 55 + y * 32));
			m_graph->AddNode(node);
		}
	}

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
