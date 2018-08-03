#include "GraphEdge.h"
#include "GraphNode.h"


GraphEdge::GraphEdge()
{
	target = nullptr;
	cost = 0;
	isHighlighted = false;

}

void GraphEdge::SetTargetNode(GraphNode * node)
{
	target = node;
}

GraphNode * GraphEdge::GetTargetNode()
{
	return target;
}

void GraphEdge::SetCost(float cost)
{
	this->cost = cost;
}

float GraphEdge::GetCost()
{
	return cost;
}


GraphEdge::~GraphEdge()
{
}
