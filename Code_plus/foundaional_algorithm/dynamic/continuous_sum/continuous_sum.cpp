#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num_count;
	int max_idx;
	int res;

	res = 0;
	cin >> num_count;
	vector<int> arr(num_count);

	for(int i = 0; i < num_count; i++)
	{
		cin >> arr[i];
	}
	max_idx = max_element(arr.begin(), arr.end()) - arr.begin();
	res = arr[max_idx];
	arr.erase(arr.begin() + max_idx);
	res = max(res, res + arr[max_element(arr.begin(), arr.end()) - arr.begin()]);

	cout << res;
}

