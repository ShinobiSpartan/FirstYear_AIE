#pragma once

class GraphNode;

class GraphEdge
{
public:
	GraphEdge();

	// Setting the target node
	void SetTargetNode(GraphNode* node);
	GraphNode* GetTargetNode();

	// Cost of the edge
	void SetCost(float cost);
	float GetCost();

	~GraphEdge();

private:
	GraphNode * target;
	float		cost;
};

