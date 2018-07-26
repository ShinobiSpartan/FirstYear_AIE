#pragma once

#include <Vector2.h>
#include <vector>
class GraphEdge;

class GraphNode
{
public:
	GraphNode();

	// Value for the node
	void SetPosition(Vector2 position);
	Vector2 GetPosition();

	// A flag to check if the node has been vistied already
	void SetVisited(bool visited);
	bool GetVisted();

	// Add connections to the node
	void AddConnections(GraphNode * node, GraphNode* target, float cost);
	std::vector<GraphEdge*> GetConnections();

	// Set the Parent
	void SetParent(GraphNode* node);
	GraphNode* GetParent();

	// Set the g-score
	void SetGScore(float gScore);
	float GetGScore();

	static bool CompareGScore(GraphNode* a, GraphNode* b);

	~GraphNode();

private:
	Vector2					m_position;
	bool					m_isVisited;
	GraphNode*				m_parent;
	float					m_gScore;
	std::vector<GraphEdge*>	m_connections;
};

