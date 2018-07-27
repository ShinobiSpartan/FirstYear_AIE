#include "GraphNode.h"
#include "GraphEdge.h"


GraphNode::GraphNode()
{
	m_parent = nullptr;
	m_isVisited = false;
	m_position = Vector2(0, 0);
}

void GraphNode::SetPosition(Vector2 position)
{
	m_position = position;
}

Vector2 GraphNode::GetPosition()
{
	return m_position;
}

void GraphNode::SetVisited(bool visited)
{
	m_isVisited = visited;
}

bool GraphNode::GetVisted()
{
	return m_isVisited;
}

void GraphNode::AddConnections(GraphNode * node, GraphNode * target, float cost)
{
	GraphEdge* newEdge = new GraphEdge();
	newEdge->SetTargetNode(target);
	newEdge->SetCost(cost);
	m_connections.push_back(newEdge);

}

std::vector<GraphEdge*> GraphNode::GetConnections()
{
	return m_connections;
}

void GraphNode::SetParent(GraphNode * node)
{
	m_parent = node;
}

GraphNode * GraphNode::GetParent()
{
	return m_parent;
}

void GraphNode::SetGScore(float gScore)
{
	m_gScore = gScore;
}

float GraphNode::GetGScore()
{
	return m_gScore;
}

void GraphNode::SetFScore(float fScore)
{
	m_fScore = fScore;
}

float GraphNode::GetFScore()
{
	return m_fScore;
}

bool GraphNode::CompareGScore(GraphNode * a, GraphNode * b)
{
	if (a->GetGScore() > b->GetGScore())
		return true;
	else
		return false;
}

bool GraphNode::CompareFScore(GraphNode * a, GraphNode * b)
{
	if (a->GetFScore() > b->GetFScore())
		return true;
	else
		return false;
}


GraphNode::~GraphNode()
{
	for (auto& edge : m_connections)
		delete edge;

	//delete m_parent;
}
