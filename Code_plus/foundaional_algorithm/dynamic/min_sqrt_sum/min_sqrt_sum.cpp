#include <iostream>
#include <vector>

using namespace std;

vector <int> dp(100000, 0);


int main()
{
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
	}

	for(int i = 1; i <= n; i++) // 바텀업 은 처음부터 채워나가야한다
	{
		for(int j = 1; j*j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i -j*j] + 1);
		}
	}

	cout << dp[n] << "\n";
}

