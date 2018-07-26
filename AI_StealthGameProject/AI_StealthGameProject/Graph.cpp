#include "Graph.h"



Graph::Graph()
{
}

void Graph::AddNode(GraphNode * node)
{
	m_nodes.push_back(node);
}

void Graph::ConnectNode(GraphNode * a, GraphNode * b, float cost)
{
	a->AddConnections(a, b, cost);
}

std::vector<GraphNode*> Graph::GetNodes()
{
	return std::vector<GraphNode*>();
}


std::vector<GraphNode*> Graph::aStarSearch(GraphNode * startNode, GraphNode * endNode)
{
	
}

Graph::~Graph()
{
}
