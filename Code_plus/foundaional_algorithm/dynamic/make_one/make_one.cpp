#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1000004,0);
// int dp[10000000];

int make_one(int input_num)
{
	if(input_num % 3 == 0)
	{
		if(dp[input_num] == 1)
		{
			return dp[input_num];
		}
		else if(dp[input_num / 3] != 0)
		{
			int temp = 1 + make_one(input_num - 1);
			dp[input_num] = 1+ dp[input_num / 3];
			if (temp < dp[input_num])
			{
				dp[input_num] = temp;
			}
			return dp[input_num];
		}
		else if(dp[input_num / 3] == 0)
		{
			int temp = 1 + make_one(input_num - 1);
			dp[input_num] = 1 + make_one(input_num / 3);
			if(temp < dp[input_num])
			{
				dp[input_num] = temp;
			}
			return dp[input_num];
		}
	}
	else if(input_num % 2 == 0)
	{
		if(input_num / 2 == 1)
		{
			dp[input_num] = 1;
			return dp[input_num];
		}
		else if(dp[input_num / 2] != 0)
		{
			int temp = 1 + make_one(input_num - 1);
			dp[input_num] = 1 + dp[input_num / 2];
			if(temp < dp[input_num])
			{
				dp[input_num] = temp;
			}
			return dp[input_num];
		}
		else if(dp[input_num / 2 == 0])
		{
			int temp = 1 + make_one(input_num - 1);
			dp[input_num] = 1 + make_one(input_num / 2);
			if(temp < dp[input_num])
			{
				dp[input_num] = temp;
			}
			return dp[input_num];
		}
	}
	else
	{
		if(input_num == 1)
		{
			return 1;
		}
		else if(dp[input_num -1] != 0)
		{
			dp[input_num] = 1 + dp[input_num -1];
			return dp[input_num];
		}
		else if(dp[input_num - 1] == 0)
		{
			dp[input_num] = 1 + make_one(input_num - 1);
			return dp[input_num];
		}
	}
	return dp[input_num];

}

int main()
{
	int input_num;

	cin >> input_num;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	int i = 999;
	while(i < input_num)
	{
		cout << "num : " << i << " output: ";
		cout << make_one(i) << "\n";
		i++;
	}

	return 0;
}
