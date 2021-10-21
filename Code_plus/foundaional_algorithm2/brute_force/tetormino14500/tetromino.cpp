#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L_shape(int **papar, int n, int m) // 객채 형태로 제공하는 방법 고민 해봐야한다
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if((2 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((1 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[1 + i][0 + j] + papar[2 + i][0 + j] + papar[2 + i][1 + j]);
		}
	}

	for(int i = 0; i < n; i++)
		{
			if((1 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((2 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[0+ i][0 + j] + papar[1 + i][0 + j] + papar[0 + i][1 + j] + papar[0 + i][2 + j]);
			}
		}

	for(int i = 0; i < n; i++)
		{
			if((2 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((1 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[0 + i][0 + j] + papar[0 + i][1 + j] + papar[1 + i][1 + j] + papar[2 + i][1 + j]);
			}
		}

	for(int i = 0; i < n; i++)
		{
			if((1 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((2 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[1 + i][0 + j] + papar[1 + i][1 + j] + papar[1 + i][2 + j] + papar[0 + i][2 + j]);
			}
		}

	for(int i = 0; i < n; i++)
		{
			if((2 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((1 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[2 + i][0 + j] + papar[2 + i][1 + j] + papar[1 + i][1 + j] + papar[0 + i][1 + j]);
			}
		}

	for(int i = 0; i < n; i++)
		{
			if((2 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((1 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[0 + i][0 + j] + papar[1 + i][0 + j] + papar[2 + i][0 + j] + papar[0 + i][1 + j]);
			}
		}

	for(int i = 0; i < n; i++)
		{
			if((1 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((2 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[0 + i][0 + j] + papar[1 + i][0 + j] + papar[1 + i][1 + j] + papar[1 + i][2 + j]);
			}
		}

	for(int i = 0; i < n; i++)
		{
			if((1 + i) > n - 1)
			{
				break;
			}
			for(int j = 0; i < m; j++)
			{
				if((2 + j) > m - 1)
				{
					break;
				}
				sum = max(sum, papar[0 + i][0 + j] + papar[0 + i][1 + j] + papar[0 + i][2 + j] + papar[1 + i][2 + j]);
			}
		}

	return sum;
}
int T_shape(int **papar, int n, int m)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if((1 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((2 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[1 + i][0 + j] + papar[1 + i][1 + j] + papar[1 + i][2 + j] + papar[0 + i][1 + j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if((2 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((1 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[1 + i][0 + j] + papar[2 + i][0 + j] + papar[1 + i][1 + j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if((1 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((2 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[0 + i][1 + j] + papar[0 + i][2 + j] + papar[1 + i][1 + j]);

		}
	}


	for(int i = 0; i < n; i++)
	{
		if((2+ i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((1 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][1 + j] + papar[1 + i][1 + j] + papar[2 + i][1 + j] + papar[1 + i][0 + j]);
		}
	}
	return sum;
}
int S_shape(int **papar, int n, int m)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		if((2 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((1 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[1 + i][0 + j] + papar[1 + i][1 + j] + papar[2 + i][1 + j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if((1 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((2 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[1 + i][0 + j] + papar[1 + i][1 + j] + papar[0 + i][1 + j] + papar[0 + i][2 + j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if((1+ i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((2 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[0 + i][1 + j] + papar[1 + i][1 + j] + papar[1 + i][2 + j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if((2+ i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((1 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][1 + j] + papar[1 + i][0 + j] + papar[1 + i][1 + j] + papar[2 + i][0 + j]);
		}
	}

	return sum;
}
int O_shape(int **papar, int n, int m)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		if((1 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((1 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[0 + i][1 + j] + papar[1 + i][0 + j] + papar[1 + i][1 + j]);
		}
	}
	return sum;
}
int I_shape(int **papar, int n, int m)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		if((3 + i) > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if(j > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[1 + i][0 + j] + papar[2 + i][0 + j] + papar[3 + i][0 + j]);
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(i > n -1)
		{
			break;
		}
		for(int j = 0; i < m; j++)
		{
			if((3 + j) > m - 1)
			{
				break;
			}
			sum = max(sum, papar[0 + i][0 + j] + papar[0 + i][1 + j] + papar[0 + i][2 + j] + papar[0 + i][3 + j]);
		}
	}
	return sum;
}


int main()
{
	vector <int> res;
	int n;
	int m;

	cin >> n;
	cin >> m;

	int **papar = new int *[n];
	for(int i = 0; i < n; i++)
	{
		papar[i] = new int[m];
	}

	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> papar[i][j];
		}
	}

	// std::cout << "L shpae:" <<L_shape(papar, n, m) << "  T shape: " << T_shape(papar, n, m) << " S shape: "<< S_shape(papar, n, m) << " O shape: " << O_shape(papar, n, m) << " I shape: " << I_shape(papar, n, m);
	int L = L_shape(papar, n, m);
	int T = T_shape(papar, n, m);
	int S = S_shape(papar, n, m);
	int O = O_shape(papar, n, m);
	int I = I_shape(papar, n, m);
	// std::cout << "\n";
	std::cout << max({L,T,S,O,I});
	std::cout << "\n";
	return 0;
}
