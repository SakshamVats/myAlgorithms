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
	Graph(int vertices);
	void addEdge(int src, int dest);
	void printNeighbours(int vertex);
	void printGraph();
	const std::vector<IntLinkedList>& getAdjList() const;
	const int getVertices() const;
};

class WeightedGraph
{
private:
	int m_vertices{};
	std::vector<WeightedIntLinkedList> adjList{};

public:
	WeightedGraph(int vertices);
	void addEdge(int src, int dest, int weight);
	void printNeighbours(int vertex);
	void printGraph();
	const std::vector<WeightedIntLinkedList>& getAdjList() const;
	const int getVertices() const;
};