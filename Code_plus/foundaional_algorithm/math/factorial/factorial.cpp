#include <iostream>

using namespace std;

int main()
{
	int input;
	int output;
	int count;

	count = 0;
	output = 1;
	cin >> input;

	if(input == 0)
	{
		cout << 1 << "\n";
		return 0;
	}
	while(count < input)
	{
		output = output * (input - count);
		count++;
	}

	cout << output << "\n";
	return 0;
}
