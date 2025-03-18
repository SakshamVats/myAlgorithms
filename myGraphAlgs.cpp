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