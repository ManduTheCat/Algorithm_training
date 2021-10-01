#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> dp(n + 1, 0);
	vector <int> p(n + 1, 0);

	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	for (int N = 1; N <= n; N++)
	{
		for(int i = 1; i <= N; i++)
		{
			if(i == 1)
			{
				dp[N] = dp[N - i] + p[i];
			}
			else
				dp[N] = min(dp[N], dp[N - i] + p[i]);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}
