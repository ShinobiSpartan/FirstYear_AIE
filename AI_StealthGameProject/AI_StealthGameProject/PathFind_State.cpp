#include "PathFind_State.h"
#include "StateMachine.h"
#include "Graph.h"
#include "GraphNode.h"
#include "Idle_State.h"


PathFind_State::PathFind_State()
{
}

PathFind_State::PathFind_State(std::vector<GraphNode*> target, Graph* graph)
{
	this->m_target = target;
	this->m_graph = graph;

	m_prevEndNode = m_target.front();
}

void PathFind_State::update(GameObject * gameObject, StateMachine * sm, float deltaTime)
{

	if (!m_target.empty())
	{
		GraphNode* nodeTarget = m_target.back();

		// find the distance (targetDist) between agent's position and target node position
		Vector2 targetDist = nodeTarget->GetPosition() - gameObject->GetPosition();

		// get the magnitude of the distance
		float magOfDist = targetDist.magnitude();

		// normalise the distance and apply some speed
		targetDist.normalise();
		targetDist = targetDist * 100;

		// difference between the agents velocity and the distance (targetDist)
		Vector2 forceOnAI = targetDist - gameObject->GetVelocity();

		// apply the force to the agent's position
		gameObject->AddForce(forceOnAI);

		// check if the player has reached the target node
		if (magOfDist < 3.0f )
		{
			m_target.pop_back();
			nodeTarget->isHighlighted = false;
		}
	}
	else
	{
		//sm->ChangeState(gameObject, new Idle_State());

		// Generate a random new end node
		GraphNode* newEndNode = m_graph->GetNodes()[rand() % 760];

		// Generate the new path with previously set random end node
		m_target = m_graph->aStarSearch(m_prevEndNode, newEndNode);
		
		// Highlight the new path that the ai will follow
		for (auto node : m_target)
		{
			node->isHighlighted = true;
		}

		// Store the end nopde of the new path for use as start node of new path
		m_prevEndNode = m_target.front();
	}
}

void PathFind_State::initiate(GameObject * gameObject)
{
}

void PathFind_State::exit(GameObject * gameObject)
{
}


PathFind_State::~PathFind_State()
{
}
