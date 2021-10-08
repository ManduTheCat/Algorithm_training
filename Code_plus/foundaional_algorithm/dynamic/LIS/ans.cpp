#include <iostream>
using namespace std;

int arr[1001], memo[1001];

inline int max(int a, int b) { return a > b ? a : b; }

int TopDown(int here)
{
	if (here == 1) return 1;

	int& ret = memo[here];
	if (ret != 0) return ret;

	ret = 1;

	for (int i = here-1; i > 0; i--)
		if (arr[i] < arr[here])
			ret = max(ret, TopDown(i) + 1);

	return ret;
}

int BottomUp(int N)
{
	for (int i = 0; i < 1001; i++)
		memo[i] = 1;

	int ret = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
			if (arr[i] > arr[j] && memo[i] < memo[j] + 1)
				memo[i] = memo[j] + 1;

		ret = max(ret, memo[i]);
	}

	return ret;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	// Top-down
	int res = 0;
	for (int i = 1; i <= N; i++)
		res = max(res, TopDown(i));
	cout << "Top-down: " << res << endl;

	// Bottom-up
	cout << "Bottom-up: " << BottomUp(N) << endl;

	return 0;
}
