#include "BootstrapGameTestApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include <exception>
#include <iostream>

BootstrapGameTestApp::BootstrapGameTestApp() {

}

BootstrapGameTestApp::~BootstrapGameTestApp() {

}

bool BootstrapGameTestApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();


	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_shipTexture = new aie::Texture("../bin/textures/ship.png");

	m_shipPosX = 100;
	m_shipPosY = 200;

	m_UiTimerThing = 0;
	
	try 
	{
		if (m_shipTexture != NULL)
		{
			return true;
		}
		else
		{
			throw std::exception();
		}
	}
	catch(std::exception e)
	{
		std::cout << "Texture was equal to NULL, please use a correct address to texture" << std::endl;
	}
}

void BootstrapGameTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_shipTexture;
}

void BootstrapGameTestApp::update(float deltaTime) {

	m_timer += deltaTime;
	m_UiTimerThing += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Use arrow keys to move the ship
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_shipPosY += 250.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_shipPosY -= 250.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_shipPosX -= 250.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_shipPosX += 250.0f * deltaTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BootstrapGameTestApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	ImGui::Begin("Useless Timer");

	// draw your stuff here!
	ImGui::SliderFloat("Time Slider", &m_UiTimerThing, 0, 100000);

	m_2dRenderer->drawSprite(m_shipTexture, m_shipPosX, m_shipPosY);
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	ImGui::End();
	m_2dRenderer->end();

}