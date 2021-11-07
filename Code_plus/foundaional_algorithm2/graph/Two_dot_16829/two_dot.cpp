#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int main()
{
	int n;
	int m;
	scanf("%d %d", &n,&m);
	char **arr = new char *[n];
	int **check = new int *[n];
	for(int i = 0; i < n; i++)
	{
		arr[i] = new char [m];
		check[i] = new int [m];
	}

	for(int i = 0; i < n; i++)
	{
		memset(check[i], 0, sizeof(int) * m);
	}

	for(int i = 0; i < n; i++)
	{
		scanf("%s", &*arr[i]);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
