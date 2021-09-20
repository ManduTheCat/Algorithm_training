#include <iostream>

using namespace std;

int f_gcd(int a, int b)
{
	int max;

	if(a < b)
		max = b;
	else
		max = a;
	while(max != 0)
	{
		if((int)((int)(a % max) == 0) && ((int)(b % max) == 0))
			return max;
		max--;
	}
	return 0;
}

int ff_gcd(int a, int b)
{
	while(b != 0)
	{
		int temp;
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int f_lcm(int a, int b)
{
	return (a * b) /ff_gcd(a, b);
}

int main()
{
	int lcm;
	int gcd;
	int input1;
	int input2;
	int cmd_count;
	cin  >> cmd_count;
	cin >> input1 >> input2;


	lcm = f_lcm(input1, input2);
	gcd = f_gcd(input1, input2);

	cout << gcd << "\n" << lcm << "\n";
}
