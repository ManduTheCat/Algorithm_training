#include <iostream>

using namespace std;

bool is_prime(int n)
{
	if(n < 2)
	{
		return false;
	}
	for(int i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;

}

int main()
{
	int min_num;
	int max_num;

	cin >> min_num;
	cin >> max_num;

	while(min_num <= max_num)
	{
		if(is_prime(min_num))
		{
			cout << min_num << "\n";
		}
		min_num++;
	}
}
