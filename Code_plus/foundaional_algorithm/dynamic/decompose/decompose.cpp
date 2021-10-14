#include <iostream>

using namespace std;

#define DIV  1000000000
int dp[201][201];

int decompose(int k, int n)
{
	int &res = dp[k][n];
	if(k == 1 )
		return 1;
	if(k == 0)
		return 0;

	if(res != 0)
		return res;

	for(int i = 0; i <= n; i++)
	{
		res += decompose(k - 1, n - i);
		res %= DIV;
	}
	return res;
}
int main()
{
	int n;
	int k;

	cin >> n;
	cin >> k;

	cout << decompose(k, n) <<  "\n";
}
