#pragma once

#include <iostream>
#include <vector>
#include "myLinkedList.h"

class Graph
{
private:
	int m_vertices{};
	std::vector<IntLinkedList> adjList{};

public:
	Graph(int vertices)
		: m_vertices(vertices), adjList(vertices)
	{}

	void addEdge(int src, int dest)
	{
		if (src < 0 || src >= m_vertices || dest < 0 || dest >= m_vertices)
		{
			std::cout << "Invalid Edge (" << src << ", " << dest << ")\n";
			return;
		}

		adjList[src].insertAtHead(dest);
		adjList[dest].insertAtHead(src); //comment out if directed graph
	}

	void printNeighbours(int vertice)
	{
		if (vertice < 0 || vertice >= m_vertices)
		{
			std::cout << "Invalid vertice " << vertice << "!\n";
			return;
		}

		std::cout << "The neighbours of vertice " << vertice << " are:\n";
		adjList[vertice].print();
	}

	void printGraph()
	{
		std::cout << "Graph:\n";

		for (int index{0}; index < m_vertices; ++index)
		{
			std::cout << "\tVertice " << index << ":\n";
			adjList[index].print();
		}
	}

	std::vector<IntLinkedList>& getAdjList()
	{
		return adjList;
	}

	int getVertices()
	{
		return m_vertices;
	}
};