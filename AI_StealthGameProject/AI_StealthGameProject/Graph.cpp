#include "Graph.h"
#include <Renderer2D.h>
#include <list>
#include <math.h>


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

void Graph::draw(aie::Renderer2D * renderer)
{
	for (auto node : m_nodes)
	{
		for (auto edge : node->GetConnections())
		{
			// Sets default colour for edges
			renderer->setRenderColour(0.6f, 0.6f, 0.6f, 0.6f);	

			// Changes the colour of the edge if it is traversed
			if (edge->isHighlighted == true)
				renderer->setRenderColour(1, 0, 0, 1);

			// Draws the edge
			renderer->drawLine(node->GetPosition().m_x, node->GetPosition().m_y, edge->GetTargetNode()->GetPosition().m_x, edge->GetTargetNode()->GetPosition().m_y, 1.0f, 1.5f);
		}

		// Sets the default colour for the nodes
		renderer->setRenderColour(0.6f, 0.6f, 0.6f, 0.5f);

		// Changes the colour of the node if it is traversed
		if (node->isHighlighted == true)
			renderer->setRenderColour(1, 0, 0, 1);
		
		// Draws the node
		renderer->drawBox(node->GetPosition().m_x, node->GetPosition().m_y, 10, 10, 0, 1);
	}
}

std::vector<GraphNode*> Graph::GetNodes()
{
	return m_nodes;
}


std::vector<GraphNode*> Graph::aStarSearch(GraphNode * startNode, GraphNode * endNode)
{
	// Sets all nodes to starting values
	for (auto n : m_nodes)
	{
		n->SetParent(nullptr);
		n->SetGScore(NULL);
		n->SetFScore(INFINITY);
		n->SetVisited(false);
	}

	std::list<GraphNode*> priorityQ;

	// Sets the values for the start node in the queue
	startNode->SetParent(nullptr);
	startNode->SetGScore(0);
	priorityQ.push_back(startNode);

	// While the queue has items in it
	while (priorityQ.size() != 0)
	{
		// Sort the queue by f-score
		priorityQ.sort(GraphNode::CompareFScore);
		// Set the current node as the back of the queue
		GraphNode* currentNode = priorityQ.back();
		// Remove the current node from the queue
		priorityQ.remove(currentNode);
		// Set the current node to visited
		currentNode->SetVisited(true);

		// For all of the edges connected to the current node
		for (auto e : currentNode->GetConnections())
		{
			// If the target node has not been visited
			if (!e->GetTargetNode()->GetVisted())
			{
				// Calculate the distance from the target node to the end node
				Vector2 dist = e->GetTargetNode()->GetPosition() - endNode->GetPosition();
				// Get the h-score by getting the magnitude of the distance
				float hScore = sqrtf(dist.m_x * dist.m_x + dist.m_y * dist.m_y);
				// Calculate the true cost from the g-score of the current node, the cost and the h-score
				float cost = currentNode->GetGScore() + e->GetCost() + hScore;

				// If the cost is smaller than the f-score of the target node
				if (cost < e->GetTargetNode()->GetFScore())
				{
					// Set the parent of the target node to the current node
					e->GetTargetNode()->SetParent(currentNode);
					// Set the f-score of the target node to cost
					e->GetTargetNode()->SetFScore(cost);
					// Push the target node into the queue
					priorityQ.push_back(e->GetTargetNode());
				}
			}
		}
	}

	std::vector<GraphNode*> enemyPath;
	// Set the current path node as the end node
	GraphNode* currentPathNode = endNode;
	// While the current path node does not equal null
	while (currentPathNode != nullptr)
	{
		for (auto edges : currentPathNode->GetConnections())
		{
			if (edges->GetTargetNode() == currentPathNode->GetParent())
			{
				edges->isHighlighted = true;
				for (auto parentEdges : currentPathNode->GetParent()->GetConnections())
				{
					if (parentEdges->GetTargetNode() == currentPathNode)
						parentEdges->isHighlighted = true;
				}
			}
		}
		// Push the current path node into the enemy path list
		enemyPath.push_back(currentPathNode);
		// Set the current path node as the parent of the current node
		currentPathNode = currentPathNode->GetParent();
	}
	return enemyPath;

}

Graph::~Graph()
{
	for (auto& node : m_nodes)
	{
		delete node;
		node = nullptr;
	}
}
