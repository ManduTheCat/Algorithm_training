#include <iostream>
#include <vector>

using namespace std;
#define DIV 1000000009
long dp[1000001];

long sum_num(long long n)
{
	long &ref = dp[n];
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	if(n == 3)
		return 4;
	if(ref > 0)
		return ref;

	ref = sum_num(n - 3) + sum_num(n - 2) + sum_num(n - 1);
	ref %= DIV;
	return ref;
}

int main()
{
	long case_num;
	long num;

	scanf("%ld",&case_num);
	vector<long> inputs;

	for(long i = 0; i < case_num; i++)
	{
		scanf("%ld",&num);
		inputs.push_back(num);
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(auto itor : inputs)
	{

		printf("%ld\n", sum_num(itor));
	}

	return 0;
}
