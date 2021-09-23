#include <iostream>

using namespace std;

void add_zero_num_factorial(long long n ,long long &count_two, long long &count_five)
{

	for(long long i = 5; i <= n; i*=5)
	{
		count_five += n /i;
	}

	for (long long i = 2; i <= n; i*=2)
	{
		count_two += n / i;
	}
}
void sub_zero_num_factorial(long long n ,long long &count_two, long long &count_five)
{

	for(long long i = 5; i <= n; i*=5)
	{
		count_five -= n /i;
	}

	for (long long i = 2; i <= n; i*=2)
	{
		count_two -= n / i;
	}
}


int main()
{
	long long n;
	long long r;
	long long count_two = 0;
	long long count_five = 0;

	cin >> n >> r;
	add_zero_num_factorial(n, count_two, count_five);
	sub_zero_num_factorial(r, count_two, count_five);
	sub_zero_num_factorial(n - r, count_two, count_five);

	cout << min(count_five,count_two) << "\n";
	return 0;
}
