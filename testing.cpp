#include "mySearches.h"
#include <algorithm>

int main()
{
	std::vector<int> arr{ 0, 15, -1, 5, 99, 5 };
	std::cout << "Linear Search:\n15 was found at index: " << myLinearSearch(arr, 15) << '\n';

	std::sort(arr.begin(), arr.end());
	std::cout << "Binary Search:\n99 was found at index: " << myBinarySearch(arr, 99) << '\n';

	return 0;
}