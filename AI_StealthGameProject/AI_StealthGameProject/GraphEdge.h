#pragma once

class GraphNode;

class GraphEdge
{
public:
	GraphEdge();

	// Setting the target node
	void SetTargetNode(GraphNode* node);
	// Get the target node
	GraphNode* GetTargetNode();

	// Set the cost of the current edge
	void SetCost(float cost);
	// Get the cost of the current edge
	float GetCost();

	~GraphEdge();

	// Checks if the edges are to be highlighted
	bool isHighlighted;

private:
	GraphNode * target;
	float		cost;
};

