#include "../includes/mySorts.h"

std::vector<int>& myInsertionSort(std::vector<int>& arr)
{
	for (int elementIndex{ 1 }; elementIndex < arr.size(); ++elementIndex)
	{
		int element{ arr[elementIndex] };
		int index{ elementIndex - 1 };

		while (index >= 0 && element < arr[index])
		{
			arr[index + 1] = arr[index];
			--index;
		}

		arr[index + 1] = element;
	}

	return arr;
}

std::vector<int>& myBubbleSort(std::vector<int>& arr)
{
	int n = static_cast<int>(arr.size());

	for (int index{ 0 }; index < n - 1; ++index)
	{
		int lastSorted{ 1 };

		for (int elementIndex{ 0 }; elementIndex < n - lastSorted; ++elementIndex)
		{
			if (arr[elementIndex] > arr[elementIndex + 1])
			{
				int temp = arr[elementIndex + 1];
				arr[elementIndex + 1] = arr[elementIndex];
				arr[elementIndex] = temp;
			}
		}

		++lastSorted;
	}

	return arr;
}

std::vector<int>& mySelectionSort(std::vector<int>& arr)
{
	for (int index{ 1 }; index < arr.size(); ++index)
	{
		int key = arr[index];
		int sortedTill{ index - 1 };

		while (sortedTill >= 0 && key < arr[sortedTill])
		{
			arr[sortedTill + 1] = arr[sortedTill];
			--sortedTill;
		}

		arr[sortedTill + 1] = key;
	}

	return arr;
}