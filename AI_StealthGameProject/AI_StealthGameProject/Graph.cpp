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
			renderer->setRenderColour(0.6f, 0.6f, 0.6f, 0.6f);	

			// Changes the colour of the edge if it is traversed
			if (edge->isHighlighted == true)
				renderer->setRenderColour(1, 0, 0, 1);

			renderer->drawLine(node->GetPosition().m_x, node->GetPosition().m_y, edge->GetTargetNode()->GetPosition().m_x, edge->GetTargetNode()->GetPosition().m_y, 1.0f, 1.5f);
		}
		renderer->setRenderColour(0.6f, 0.6f, 0.6f, 0.5f);
		// Changes the colour of the node if it is traversed
		if (node->isHighlighted == true)
			renderer->setRenderColour(1, 0, 0, 1);
		
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

	startNode->SetParent(nullptr);
	startNode->SetGScore(0);
	priorityQ.push_back(startNode);

	while (priorityQ.size() != 0)
	{
		priorityQ.sort(GraphNode::CompareFScore);
		GraphNode* currentNode = priorityQ.back();
		priorityQ.remove(currentNode);
		currentNode->SetVisited(true);

		for (auto e : currentNode->GetConnections())
		{
			if (!e->GetTargetNode()->GetVisted())
			{
				Vector2 dist = e->GetTargetNode()->GetPosition() - endNode->GetPosition();
				float hScore = sqrtf(dist.m_x * dist.m_x + dist.m_y * dist.m_y);
				float cost = currentNode->GetGScore() + e->GetCost() + hScore;

				if (cost < e->GetTargetNode()->GetFScore())
				{
					e->GetTargetNode()->SetParent(currentNode);
					e->GetTargetNode()->SetFScore(cost);
					priorityQ.push_back(e->GetTargetNode());
				}
			}
		}
	}

	std::vector<GraphNode*> enemyPath;
	GraphNode* currentPathNode = endNode;
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

		enemyPath.push_back(currentPathNode);
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
