#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include "StateMachine.h"

class AI_StealthGameProjectApp : public aie::Application {
public:

	AI_StealthGameProjectApp();
	virtual ~AI_StealthGameProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*			m_2dRenderer;
	aie::Font*					m_font;
	StateMachine				m_finiteStateMachine;
	std::vector<GameObject*>	m_gameObjects;

};