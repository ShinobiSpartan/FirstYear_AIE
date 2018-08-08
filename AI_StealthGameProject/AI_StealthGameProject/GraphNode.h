#pragma once

#include <Vector2.h>
#include <vector>
class GraphEdge;

class GraphNode
{
public:
	GraphNode();

	// Set position value for the node
	void SetPosition(Vector2 position);
	// Get position value for the node
	Vector2 GetPosition();

	// A bool to check if the node has been vistied already
	void SetVisited(bool visited);
	// Return whether the node has been visited or not
	bool GetVisted();

	// Add connections to the node
	void AddConnections(GraphNode * node, GraphNode* target, float cost);
	// Get the number of connections to this node
	std::vector<GraphEdge*> GetConnections();

	// Set the parent node
	void SetParent(GraphNode* node);
	// Get the parent node of the current node
	GraphNode* GetParent();

	// Set the g-score
	void SetGScore(float gScore);
	// Get the g-score of a node
	float GetGScore();

	// Set the f-score
	void SetFScore(float fScore);
	// Get the f-score of a node
	float GetFScore();

	// Compares two g-scores to find shortest path
	static bool CompareGScore(GraphNode* a, GraphNode* b);
	// Compares two f-scores to find the shortest path
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

