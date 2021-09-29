#include <iostream>
#include <vector>

using namespace std;

vector <int> dp(15,0);

int make_num(int n)
{
	if(dp[n] != 0)
	{
		return dp[n];
	}
	else if(dp[n] == 0)
		dp[n] = make_num(n - 3)+ make_num(n - 2) + make_num(n - 1);

	return dp[n];
}


int main()
{
	int n;
	int cmd_count;
	cin >> cmd_count;
	while(cmd_count--)
	{
		cin  >> n;
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2; //1,1 2
		dp[3] = 4;//111 12 3 21
		dp[4] = 7;

		cout <<	make_num(n) << "\n";
	}
}
