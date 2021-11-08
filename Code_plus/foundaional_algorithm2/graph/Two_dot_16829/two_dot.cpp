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
int count;
int flag;
int cordex_x;
int cordex_y;

void dfs(int x, int y, int befor_x, int befor_y, char **&arr, int **&check, char alpha)
{
	count++;
	if(check != 0 && check[x][y] >= 4 )
	{
		// printf("bumped\n");
		flag = 1;
	}
	if(check[x][y] == 0)
	{
		check[x][y] = count;
		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(n > nx && m > ny && nx >= 0 && ny >= 0)
			{
				if(!(nx == befor_x && ny == befor_y))
				{
					if(arr[nx][ny] == alpha)
					{
						dfs(nx, ny, x, y, arr, check, alpha);
					}
				}
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
				flag = 0;
				count = 0;
				cordex_x = i;
				cordex_x = j;
				dfs(i, j, -1, -1,arr, check, arr[i][j]);
				if(flag == 1)
				{
					printf("YES\n");
					return;
				}
			}
		}
	}
	if(flag == 0)
	{
		printf("NO\n");
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

	// for(int i = 0; i < n; i++)
	// {
	// 	for(int j = 0; j < m; j++)
	// 	{
	// 		printf("%d ", check[i][j]);
	// 	}
	// 	printf("\n");
	// }

	return 0;
}
