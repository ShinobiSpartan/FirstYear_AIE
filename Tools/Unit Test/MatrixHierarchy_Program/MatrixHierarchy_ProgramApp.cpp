#include "MatrixHierarchy_ProgramApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

MatrixHierarchy_ProgramApp::MatrixHierarchy_ProgramApp() {

}

MatrixHierarchy_ProgramApp::~MatrixHierarchy_ProgramApp() {

}

bool MatrixHierarchy_ProgramApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	
	// load the sprites in
	m_tank = new SpriteObject("../bin/textures/Tank.png");
	m_turret = new SpriteObject("../bin/textures/GunTurret_Long.png");

	// attach turret to top of tank
	m_tank->addChild(m_turret);

	// center the tank
	m_tank->setPosition(getWindowWidth() / 2.f, getWindowHeight() / 2.f);

	return true;
}

void MatrixHierarchy_ProgramApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_tank;
	delete m_turret;
}

void MatrixHierarchy_ProgramApp::update(float deltaTime) {

	m_tank->update(deltaTime);

	// access input
	auto input = aie::Input::getInstance();
	
	m_tank->translate(m_tank->getForces().m_x, m_tank->getForces().m_y);
	m_tank->reduceForce();

	// rotate tank, using deltaTime as the rotation speed
	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_tank->rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_tank->rotate(-deltaTime);

	// move tank, the 100 magic-number represents speed
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{ 
		m_tank->addForce( m_tank->getLocalTransform()[1].m_x * deltaTime * 100, 
						  m_tank->getLocalTransform()[1].m_y * deltaTime * 100 );
	}

	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_tank->addForce( m_tank->getLocalTransform()[1].m_x * deltaTime * -100,	
						  m_tank->getLocalTransform()[1].m_y * deltaTime * -100 );
	}

	// rotate turret
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_turret->rotate(deltaTime);
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_turret->rotate(-deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void MatrixHierarchy_ProgramApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_tank->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}