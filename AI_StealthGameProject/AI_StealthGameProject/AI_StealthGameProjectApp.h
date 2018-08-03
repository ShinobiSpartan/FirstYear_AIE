#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include "StateMachine.h"

class GameObject;
class Graph;
class GraphNode;


class AI_StealthGameProjectApp : public aie::Application {
public:

	AI_StealthGameProjectApp();
	virtual ~AI_StealthGameProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	// Function to generate graph
	void CreateGraph();

protected:

	aie::Renderer2D*			m_2dRenderer;
	aie::Font*					m_font;
	Application*				m_Application;
	StateMachine*				m_finiteStateMachine;
	Graph*						m_graph;
	std::vector<GameObject*>	m_gameObjects;
	std::vector<GraphNode*>		m_targetPath;


};