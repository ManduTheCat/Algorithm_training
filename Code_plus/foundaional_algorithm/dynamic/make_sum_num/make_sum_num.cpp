#include <iostream>
#include <vector>

using namespace std;

vector <int> dp(15,0);

int main()
{
	int n;
	cin  >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2; //1,1 2
	dp[3] = 4;//111 12 3 21

	dp[n] = 1 + dp [n -1]


}
