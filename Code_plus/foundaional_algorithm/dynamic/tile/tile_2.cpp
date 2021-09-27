#include <iostream>
#include <vector>

using namespace std;

vector <int> d(1000 ,0);

int tile(int n)
{
	if(n == 0)
		return 0;
	if(d[n] > 0)
	{
		return d[n] % 10007;
	}
	else if(d[n] == 0)
	{
		d[n] = tile(n -1) + 2* tile(n -2);
		return d[n] % 10007;
	}
	return d[n] % 10007;
}

int main()
{
	d[0] = 1;
	d[1] = 1;
	d[2] = 3;
	int n;
	cin >> n;
	cout << tile(n) << "\n";
}
