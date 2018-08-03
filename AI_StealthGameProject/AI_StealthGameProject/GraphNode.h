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

	// Set the f-score
	void SetFScore(float fScore);
	float GetFScore();

	// Compares two scores to find shortest path
	static bool CompareGScore(GraphNode* a, GraphNode* b);
	static bool CompareFScore(GraphNode* a, GraphNode* b);

	// Checks if the nodes are to be highlighted
	bool isHighlighted;

	~GraphNode();

private:
	Vector2					m_position;
	bool					m_isVisited;
	GraphNode*				m_parent;
	float					m_gScore;
	float					m_fScore;
	float					m_hScore;
	std::vector<GraphEdge*>	m_connections;
};

