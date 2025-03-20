#include "../includes/myGraphAlgs.h"

void dfsHelper(int node, Graph& graph,
	std::unordered_set<int>& visited, std::vector<int>& result)
{
	visited.insert(node);
	result.push_back(node);

	const IntLinkedList& neighbours{ graph.getAdjList()[node] };

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

			const IntLinkedList& neighbours{ graph.getAdjList()[fNode] };
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

void dijkstra(const WeightedGraph& graph, int start)
{
	int vertices = graph.getVertices();
	std::vector<int> dist(vertices, std::numeric_limits<int>::max());
	dist[start] = 0;

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq{};
	pq.push({ 0, start });

	const std::vector<WeightedIntLinkedList>& adjList = graph.getAdjList();

	while (!pq.empty())
	{
		int currentDist = pq.top().first;
		int currentVertex = pq.top().second;
		pq.pop();

		if (currentDist > dist[currentVertex]) 
			continue;

		WeightedIntNode* neighbor = adjList[currentVertex].getHead();
		while (neighbor)
		{
			int newDist = currentDist + neighbor->weight;

			if (newDist < dist[neighbor->vertex])
			{
				dist[neighbor->vertex] = newDist;
				pq.push({ newDist, neighbor->vertex });
			}

			neighbor = neighbor->next;
		}
	}

	std::cout << "Shortest distances from vertex " << start << ":\n";
	for (int i = 0; i < vertices; ++i)
	{
		std::cout << "Vertex " << i << " : " 
			<< (dist[i] == std::numeric_limits<int>::max() ? -1 : dist[i]) << "\n";
	}
}

