#include <iostream>

using namespace std;

int main()
{
	int c_count;
	int input_num;
	// int *dp;

	cin >> input_num;
	// dp = new int[input_num + 1];
	c_count = 0;

	while(input_num != 1)
	{
		if(input_num %3 == 0)
		{
			input_num /= 3;
			c_count++;
		}
		else if(input_num %2 == 0)
		{
			input_num /= 2;
			c_count++;
		}
		else
		{
			input_num -=1;
			c_count++;
		}
	}

	cout << c_count << "\n";
	return 0;
}