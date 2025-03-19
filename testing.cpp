#include "includes/mySearches.h"
#include "includes/mySorts.h"
#include "includes/myGraphAlgs.h"

void testSortsAndSearches();
void testGraphAlgs();

int main()
{
	testGraphAlgs();

	return 0;
}

void testSortsAndSearches()
{
	std::vector<int> arr{ 0, 15, -1, 5, 99, 50 };
	std::cout << "Linear Search:\n15 was found at index: " << myLinearSearch(arr, 15) << '\n';

	//myInsertionSort(arr)
	//myBubbleSort(arr)
	mySelectionSort(arr);

	for (auto i : arr)
		std::cout << i << ' ';

	std::cout << "\nBinary Search:\n99 was found at index: " << myBinarySearch(arr, 99) << '\n';

	std::cout << "Interpolation Search:\n50 was found at index: " << myInterpolationSearch(arr, 50) << '\n';
}

void testGraphAlgs()
{
	Graph sakshamsGraph(4);
	sakshamsGraph.addEdge(0, 1);
	sakshamsGraph.addEdge(0, 2);
	sakshamsGraph.addEdge(1, 2);
	sakshamsGraph.addEdge(1, 3);

	//sakshamsGraph.printGraph();

	std::vector<int> dfsResult{ depthFirstSearch(sakshamsGraph) };

	std::cout << "Depth First Search Result:\n";
	for (int i : dfsResult)
		std::cout << i << ' ';
	std::cout << '\n';

	std::vector<int> bfsResult{ breadthFirstSearch(sakshamsGraph) };

	std::cout << "Breadth First Search Result:\n";
	for (int i : bfsResult)
		std::cout << i << ' ';\
	std::cout << '\n';

	WeightedGraph sWGraph(4);
	sWGraph.addEdge(0, 1, 3);
	sWGraph.addEdge(0, 2, 6);
	sWGraph.addEdge(1, 2, 2);
	sWGraph.addEdge(1, 3, 5);


	dijkstra(sWGraph, 0);
}