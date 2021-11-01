#include <iostream>
#include <queue>
#include <utility>
#include <string.h>

using namespace std;

int main()
{
	int n;
	int m;
	scanf("%d %d", &n,&m);

	int **arr = new int*[n];
	int **check = new int*[n];

	for(int i = 0; i < n;  i++)
	{
		arr[i] = new int [m];
		check[i] = new int [m];
	}

	for(int i = 0; i < n; i++)
	{
		memset(check[i], 0, sizeof(int) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

}
