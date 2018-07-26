#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "SpriteObject.h"

class MatrixHierarchy_ProgramApp : public aie::Application {
public:

	MatrixHierarchy_ProgramApp();
	virtual ~MatrixHierarchy_ProgramApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	SpriteObject* m_tank;
	SpriteObject* m_turret;
};