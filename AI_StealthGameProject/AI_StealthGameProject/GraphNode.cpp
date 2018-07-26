#include "GraphNode.h"
#include "GraphEdge.h"


GraphNode::GraphNode()
{
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
	newEdge->SetNode(target);
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

bool GraphNode::CompareGScore(GraphNode * a, GraphNode * b)
{
	if (a->GetGScore() < b->GetGScore())
		return false;
	else
		return true;
}


GraphNode::~GraphNode()
{
}
