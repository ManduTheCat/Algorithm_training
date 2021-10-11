#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num_count;

	cin >> num_count;
	vector<int> arr(num_count);
	vector<int> dp(num_count);

	for(int i = 0; i < num_count; i++)
	{
		cin >> arr[i];
	}

	for(int i = 0; i < num_count; i++)
	{
		if( i != 0)
			dp[i] = max(arr[i], arr[i] + dp[i - 1]);
		else
			dp[0] = arr[0];
	}

	int res;
	res = *max_element(dp.begin(), dp.end());
	cout << res << "\n";
}

