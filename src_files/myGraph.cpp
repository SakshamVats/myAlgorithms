#include "../includes/myGraph.h"

Graph::Graph(int vertices)
	: m_vertices(vertices), adjList(vertices)
{}

void Graph::addEdge(int src, int dest)
{
	if (src < 0 || src >= m_vertices || dest < 0 || dest >= m_vertices)
	{
		std::cout << "Invalid Edge (" << src << ", " << dest << ")\n";
		return;
	}

	adjList[src].insertAtHead(dest);
	adjList[dest].insertAtHead(src); //comment out if directed graph
}

void Graph::printNeighbours(int vertex)
{
	if (vertex < 0 || vertex >= m_vertices)
	{
		std::cout << "Invalid vertice " << vertex << "!\n";
		return;
	}

	std::cout << "The neighbours of vertex " << vertex << " are:\n";
	adjList[vertex].print();
}

void Graph::printGraph()
{
	std::cout << "Graph:\n";

	for (int index{ 0 }; index < m_vertices; ++index)
	{
		std::cout << "\tVertex " << index << ":\n";
		adjList[index].print();
	}
}

const std::vector<IntLinkedList>& Graph::getAdjList() const
{
	return adjList;
}

const int Graph::getVertices() const
{
	return m_vertices;
}



WeightedGraph::WeightedGraph(int vertices)
	: m_vertices(vertices), adjList(vertices)
{}

void WeightedGraph::addEdge(int src, int dest, int weight)
{
	if (src < 0 || src >= m_vertices || dest < 0 || dest >= m_vertices)
	{
		std::cout << "Invalid Edge (" << src << ", " << dest << ")\n";
		return;
	}

	adjList[src].insertAtHead(dest, weight);
	adjList[dest].insertAtHead(src, weight); //comment out if directed graph
}

void WeightedGraph::printNeighbours(int vertex)
{
	if (vertex < 0 || vertex >= m_vertices)
	{
		std::cout << "Invalid vertex " << vertex << "!\n";
		return;
	}

	std::cout << "The neighbors of vertex " << vertex << " are:\n";
	adjList[vertex].print();
}

void WeightedGraph::printGraph()
{
	std::cout << "Graph:\n";

	for (int index{ 0 }; index < m_vertices; ++index)
	{
		std::cout << "\tVertex " << index << ":\n";

		WeightedIntNode* curr = adjList[index].getHead();
		while (curr)
		{
			std::cout << " -> (" << curr->vertex << ", weight: " << curr->weight << ")";
			curr = curr->next;
		}

		std::cout << " -> null\n";
	}
}

const std::vector<WeightedIntLinkedList>& WeightedGraph::getAdjList() const
{
	return adjList;
}

const int WeightedGraph::getVertices() const
{
	return m_vertices;
}