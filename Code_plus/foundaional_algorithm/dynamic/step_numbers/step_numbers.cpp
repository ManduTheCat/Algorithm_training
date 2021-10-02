#include <iostream>
#include <vector>
using namespace std;

#define MODENUM 1000000000;

vector <int> dp(101, 0);
int numbers[10][2];

long long step_numbers(long long N)
{
	long long count = 0;
	if(N == 1)
	{
		return 9;
	}
		for(int i = 0; i <= 9; i++)
		{
			for(int j = 1; j < N; j++)
			{
				for(int k = 1; k <= 2; k++)
				{
					if(numbers[i][k] == 9)
					{
						numbers[i][k] = i - 1;
						count+=1;
						count%= MODENUM;
					}
					else if(numbers[i][k] <= 1)
					{
						numbers[i][k] = i + 1;
						count+=1;
						count%= MODENUM;
					}
					else
					{
						numbers[i][2] = i + 1;
						numbers[i][1] = i - 1;
						count+=2;
						count%= MODENUM;
					}
				}
			}
		}
	return count;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i <= 10; i++)
	{
		numbers[i][1] = 1;
		numbers[i][2] = 1;
	}

	cout << step_numbers(n) << "\n";
	return 0;
}
