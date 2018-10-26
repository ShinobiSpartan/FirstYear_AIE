#pragma once

#include "Application.h"
#include "Renderer2D.h"

class BootstrapGameTestApp : public aie::Application {
public:

	BootstrapGameTestApp();
	virtual ~BootstrapGameTestApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_shipTexture;

	float m_shipPosX, m_shipPosY;
	float m_timer;

	float m_UiTimerThing;
};