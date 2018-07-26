#include "GraphNode.h"



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
}

std::vector<GraphEdge*> GraphNode::GetConnections()
{
	return std::vector<GraphEdge*>();
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
	if (a < b)
		return false;
	else
		return true;
}


GraphNode::~GraphNode()
{
}
