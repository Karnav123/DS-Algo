#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(vector<int> *array, int low, int high)
{
	int p = 0;

	int pivot = high;
	int i = low - 1;

	for (int j = low; j <= high - 1; ++j)
	{
		if (array->at(j) <= array->at(pivot))
		{
			i++;
			swap(array->at(i), array->at(j));
		}
	}
	swap(array->at(i + 1), array->at(pivot));

	return i + 1;
}

void quickSortUtils(vector<int> *array, int low, int high)
{
	if (low < high)
	{
		int p = partition(array, low, high);
		quickSortUtils(array, low, p - 1);
		quickSortUtils(array, p + 1, high);
	}
}
vector<int> quickSort(vector<int> array) {
	// Write your code here.

	int low = 0;
	int high = array.size() - 1;
	quickSortUtils(&array, low, high);

	return array;
}

int main()
{
	vector<int> result = quickSort({ -4, 5, 10, 8, -10, -6, -4, -2, -5, 3, 5, -4, -5, -1, 1, 6, -7, -6, -7, 8 });
	for (int i : result)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}