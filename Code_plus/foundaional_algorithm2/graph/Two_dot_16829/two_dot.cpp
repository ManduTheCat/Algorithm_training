#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

int n;
int m;
int dx[4] = {0, 0 , -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, char **&arr, int **&check, int count, char alpha)
{
	count++;
	if(check[x][y] == 0)
	{
		check[x][y] = count;
		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx >= 0 && ny >= 0 && n > nx && m > ny && check[nx][ny] == 0 && arr[nx][ny] == alpha)
			{
				dfs(nx, ny, arr, check, count, alpha);
			}
		}
	}
}

void intput_to_dfs_solution(char **&arr, int **&check)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(check[i][j] == 0)
			{
				dfs(i, j, arr, check, 0, arr[i][j]);
			}
		}
	}

}


int main()
{
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


	intput_to_dfs_solution(arr, check);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}

	return 0;
}
