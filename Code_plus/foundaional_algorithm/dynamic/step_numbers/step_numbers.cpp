#include <iostream>
#include <vector>
using namespace std;

#define MODENUM 1000000000;
#define LL long long;

vector <int> dp(101, 0);
vector <int> count(10, 1);

int step_numbers(int N)
{
	for(int n = 1; n <= N; n++)
	{
		for(int i = 1; i <= 10; i++)
		{

		}
	}

	return dp[N];

}
int main()
{
	int n;
	cin >> n;
	count[0] = 0;

	if(n == 1)
		dp[1] = 9;


	return 0;
}
