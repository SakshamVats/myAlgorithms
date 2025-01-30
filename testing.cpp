#include "mySearches.h"
#include "mySorts.h"

int main()
{
	std::vector<int> arr{ 0, 15, -1, 5, 99, 50};
	std::cout << "Linear Search:\n15 was found at index: " << myLinearSearch(arr, 15) << '\n';

	myInsertionSort(arr);
	std::cout << "Binary Search:\n99 was found at index: " << myBinarySearch(arr, 99) << '\n';

	std::cout << "Interpolation Search:\n50 was found at index: " << myInterpolationSearch(arr, 50) << '\n';

	return 0;
}