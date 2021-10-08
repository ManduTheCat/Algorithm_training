#include <iostream>
#include <vector>
using namespace std;

vector <int> inputs(1001, 0);
vector <int> dp (1001, 0);
int LIS(int here)
{
	if(here == 1)
		return 1;

	int &ref = dp[here];
	if(ref != 0)
		return ref;

	ref = 1;

	for(int i = here - 1; i > 0; i-- )
	{
		if (inputs[i] < inputs[here])
		{
			ref = max(ref, LIS(i) + 1);
		}
	}
	return ref;
}

int main()
{
	int numcount;
	int res;

	res = 0;
	cin  >> numcount;

	for(int i= 1; i <= numcount; i++)
	{
		cin >> inputs[i];
	}

	for(int i = 1; i <= numcount; i++)
	{
		res = max(res, LIS(i));
	}

	cout << res << "\n";

	return 0;
}
