#include <iostream>
#include <string.h>
using namespace std;

#define MOD 1000000000;


int dp[101][10];

int step_num(int n, int l)
{
	int &ref = dp[n][l];
	if(n == 1)
	{
		if (l == 0)
			return 0;
		else
			return 1;
	}
	if(ref != -1)
		return ref;
	if(l == 0)
	{
		return ref = step_num(n - 1, 1) % MOD;
	}
	if(l == 9)
	{
		return ref = step_num(n - 1, 8) % MOD;
	}
	else
		return ref =  (step_num(n -1 , l + 1) + step_num(n - 1, l - 1)) % MOD;

}

int main()
{
	int sum = 0;
	int n ;

	cin >> n;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i <= 9; i++)
	{
		sum += step_num(n, i);
		sum %= MOD ;//이거추가하니 해결됨 띠벌
	}
	cout << sum << "\n";
	return 0;
}

