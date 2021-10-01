#include <iostream>
#define MODENUM  1000000009
using namespace std;


long long d[1000001][4];

long long find_sum(int n)
{
	if(d[n - 1][0] == 0)
	{
		d[n-1][0] = find_sum(n - 1);
	}
	for(int i = 4; i <= n; i++)
	{
		d[n][1] = (d[n - 1][2] + d[n - 1][3]) % MODENUM;
		d[n][2] = (d[n - 2][3] + d[n - 2][1]) % MODENUM;
		d[n][3] = (d[n - 3][1] + d[n - 3][2]) % MODENUM;
		d[n][0] = (d[n][1] + d[n][2] + d[n][3]) % MODENUM;
	}
	return d[n][0];
}

int main()
{
	int n;
	int test_count;

	cin >> test_count;


	for(int i = 0; i < 4; i++)
		d[0][i] = 0;
	while(test_count--)
	{
		cin >> n;

		d[1][0] = 1;
		d[1][1] = 1;
		d[1][2] = 0;
		d[1][3] = 0;
		d[2][0] = 1;
		d[2][1] = 0;
		d[2][2] = 1;
		d[2][3] = 0;
		d[3][0] = 3;
		d[3][1] = 1;
		d[3][2] = 1;
		d[3][3] = 1;

		cout << find_sum(n) << "\n";
	}


}
