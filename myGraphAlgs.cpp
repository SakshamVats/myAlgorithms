#include "includes/myGraphAlgs.h"

void dfsHelper(int node, Graph& graph,
	std::unordered_set<int>& visited, std::vector<int>& result)
{
	visited.insert(node);
	result.push_back(node);

	IntLinkedList& neighbours{ graph.getAdjList()[node] };

	IntNode* curr{ neighbours.getHead() };

	while (curr)
	{
		if (!visited.count(curr->data))
		{
			dfsHelper(curr->data, graph, visited, result);
		}

		curr = curr->next;
	}
}

std::vector<int> depthFirstSearch(Graph& graph)
{
	std::vector<int> result{};
	std::unordered_set<int> visited{};

	for (int node{ 0 }; node < graph.getVertices(); ++node)
	{
		if (!visited.count(node))
		{
			dfsHelper(node, graph, visited, result);
		}
	}

	return result;
}

std::vector<int> breadthFirstSearch(Graph& graph)
{
	std::vector<int> result{};
	std::unordered_set<int> visited{};
	std::queue<int> q{};

	for (int node{ 0 }; node < graph.getVertices(); ++node)
	{
		if (visited.count(node))
			continue;

		q.push(node);
		visited.insert(node);

		while (!q.empty())
		{
			int fNode = q.front();
			q.pop();
			result.push_back(fNode);

			IntLinkedList& neighbours{ graph.getAdjList()[fNode] };
			IntNode* curr{ neighbours.getHead() };

			while (curr)
			{
				if (!visited.count(curr->data))
				{
					q.push(curr->data);
					visited.insert(curr->data);
				}
				curr = curr->next;
			}
		}
	}

	return result;
}