#pragma once

#include "GraphEdge.h"
#include "GraphNode.h"

namespace aie
{
	class Renderer2D;
}

class Graph
{
public:
	Graph();
	
	// Adds node to the graph
	void AddNode(GraphNode* node);

	// Connects two nodes in the graph
	void ConnectNode(GraphNode* a, GraphNode* b, float cost);

	// Get the nodes
	std::vector<GraphNode*> GetNodes();

	// Djisktra shortest path search
	std::vector<GraphNode*> aStarSearch(GraphNode* startNode, GraphNode* endNode);

	~Graph();

private:
	std::vector<GraphNode*> m_nodes;
};

