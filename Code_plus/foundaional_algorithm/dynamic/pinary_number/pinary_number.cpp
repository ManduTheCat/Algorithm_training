#include <iostream>
#include <string.h>
using namespace std;

long long dp[91][2];

long long pinary_num(int n , int l)
{
	long long &ref = dp[n][l];
	if(n == 1)
	{
		if(l == 1)
			return 1;
		else
			return 0;
	}

	if(ref != -1)
	{
		return ref;
	}

	if(l == 1)
		return ref = pinary_num(n - 1, 0);
	else
		return ref = (pinary_num(n - 1, 1) + pinary_num(n - 1, 0));
}

int main()
{
	long long ans = 0;
	int n;
	cin >> n;
	memset(dp , -1, sizeof(dp));
	for(int i = 0; i <= 1; i++)
	{

		ans += pinary_num(n, i);
	}
	cout << ans << "\n";
}
