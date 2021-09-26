#include <iostream>
using namespace std;


int dp[41];

int f_fibo(int n)
{
	if(n <= 0)
	{
		dp[0] = 0;
		return 0;
	}
	else if(n == 1)
	{
		dp[1] = 1;
		return 1;
	}

	if(dp[n] != 0)
	{
		return dp[n];
	}
	else
	{
		return dp[n] = f_fibo(n -1) + f_fibo(n-2);
	}


}

int main()
{
	int cmd_num;

	int n;

	cin >> cmd_num;
	while(cmd_num--)
	{

		cin >> n;
		int r;
		int befor_r;

		if(n == 0)
		{
			cout << "1" << " " << "0" << "\n";
		}
		else if(n == 1)
		{
			cout << "0" << " " << "1" << "\n";
		}
		else{
			r = f_fibo(n);
			befor_r = f_fibo(n -1);
			cout << befor_r << " " << r << "\n";
		}
	}
}
