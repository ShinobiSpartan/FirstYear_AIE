#include "AI_StealthGameProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "GameObject.h"
#include "KeyboardController.h"
#include "StateMachine.h"
#include "Seek_State.h"
#include "Pursue_State.h"
#include "Wander_State.h"

AI_StealthGameProjectApp::AI_StealthGameProjectApp() {

}

AI_StealthGameProjectApp::~AI_StealthGameProjectApp() {

}

bool AI_StealthGameProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	GameObject* m_player = new GameObject(new aie::Texture("../bin/textures/Player_Knife.png"), Vector2(10, 20));
	GameObject* m_ai = new GameObject(new aie::Texture("../bin/textures/Enemy_Sprite.png"), Vector2(400, 400));

	m_ai->AddForce(Vector2(100, 200));

	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_ai);

	m_player->AddBehaviour(new KeyboardController(aie::Input::getInstance()));

	m_finiteStateMachine.ChangeState(m_ai, new Wander_State(m_player, 0.0f, 10.0f, 2.0f));
	m_ai->AddBehaviour(&m_finiteStateMachine);

	return true;
}

void AI_StealthGameProjectApp::shutdown() {

	for (auto gameObject : m_gameObjects)
		delete gameObject;
	delete m_font;
	delete m_2dRenderer;
}

void AI_StealthGameProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

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

	// draw your stuff here!
	for (auto gameObject : m_gameObjects)
		gameObject->draw(m_2dRenderer);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}