#pragma once
#include "State.h"
#include <list>

class Graph;
class GraphNode;

class PathFind_State : public State
{
public:
	PathFind_State();
	PathFind_State(std::vector<GraphNode*> target, Graph* graph);
	virtual void update(GameObject* gameObject, StateMachine* sm, float deltaTime);
	virtual void initiate(GameObject* gameObject);
	virtual void exit(GameObject* gameObject);

	~PathFind_State();

private:
	std::vector<GraphNode*>	m_target;
	Graph*					m_graph;
	GraphNode*				m_prevEndNode;
};

