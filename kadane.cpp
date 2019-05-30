#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
	// Write your code here.
	int maxSoFar = array[0];
	int maxGlobal = array[0];

	for (int i = 1; i < array.size(); ++i)
	{
		int temp = maxSoFar + array[i];
		maxSoFar = max(array[i], temp);
		maxGlobal = max(maxSoFar, maxGlobal);
	}

	return maxGlobal;
}

int main()
{
	vector<int> v;

	/*for (int i = 0; i < 10; ++i)
	{
		v.push_back(i+1);
	}*/

	int ans = kadanesAlgorithm({ -10, -2, -9, -4, -8, -6, -7, -1, -3, -5 });
	cout << ans << endl;
	return 0;
}