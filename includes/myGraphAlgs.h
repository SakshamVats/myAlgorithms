#pragma once

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <limits>
#include "myGraph.h"

std::vector<int> depthFirstSearch(Graph& graph);
std::vector<int> breadthFirstSearch(Graph& graph);
void dijkstra(const WeightedGraph& graph, int start);