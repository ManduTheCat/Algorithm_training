#include <iostream>

using namespace std;


int main()
{
	int num;
	cin  >> num;
	int count = 0;
	for(int i = 5; i <= num; i*=5)
	{
		count += num / i;
	}

	cout << count << "\n";
}
