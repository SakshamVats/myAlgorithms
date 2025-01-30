#pragma once

#include <iostream>
#include <vector>

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