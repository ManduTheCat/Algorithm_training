#include <iostream>

using namespace std;

bool f_is_prime(int n)
{
	if(n < 2)
	{
		return false;
	}
	for (int i = 2; i*i <= n ; i++)
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
	int max_num;
	int *numlist;
	int i = 0;
	int count = 0;

	cin >> max_num;
	numlist =  new int[max_num];
	while(i < max_num)
	{
		cin >> numlist[i];
		if(f_is_prime(numlist[i]))
		{
			count ++;
		}
		i++;
	}


	cout << count << "\n";
	delete numlist;
	return 0;
}
