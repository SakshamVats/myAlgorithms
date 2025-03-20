#include "../includes/mySearches.h"

int myLinearSearch(const std::vector<int>& arr, int key)
{
	for (int index{ 0 }; index < arr.size(); ++index)
	{
		if (key == arr[index])
			return index;
	}

	return -1;
}

int myBinarySearch(const std::vector<int>& arr, int key)
{
	int size{ static_cast<int>(arr.size()) };

	int max{ size - 1 };
	int min{ 0 };

	while (min <= max)
	{
		int middle{ (min + max) / 2 };

		if (key == arr[middle])
			return middle;

		else if (key > arr[middle])
			min = middle + 1;

		else
			max = middle - 1;
	}

	return -1;
}

int myInterpolationSearch(const std::vector<int>& arr, int key)
{
	int size{ static_cast<int>(arr.size()) };

	int max{ size - 1 };
	int min{ 0 };

	while (min <= max && key >= arr[min] && key <= arr[max])
	{
		int pos{ min + static_cast<int>((key - arr[min]) * (max - min) / (arr[max] - arr[min])) };

		if (pos < min || pos > max)
			return -1;

		if (key == arr[pos])
			return pos;

		else if (key > arr[pos])
			min = pos + 1;

		else
			max = pos - 1;
	}

	return -1;
}