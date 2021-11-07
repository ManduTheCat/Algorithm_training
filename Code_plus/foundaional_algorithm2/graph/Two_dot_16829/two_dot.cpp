#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

void bfs_solution(int n, int m, char **&arr, int **&check)
{
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0 ,0};
	int nx, ny;
	int x, y;
	char alpha;
	int beside_check;
	queue <pair<int, int>> q;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(check[i][j] == 0)
			{
				alpha = arr[i][j];
				q.push(make_pair(i, j));
				check[i][j] = 1;
				while(!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					beside_check = 0;
					for(int d = 0; d < 4; d++)
					{
						nx = x + dx[d];
						ny = y + dy[d];
						if(nx >= 0 && ny >= 0 && n > nx && x > ny && check[nx][ny] == 0 && arr[nx][ny] == alpha)
						{
							beside_check++;
							q.push(make_pair(nx, ny));
							check[nx][ny] = beside_check;
						}
					}
				}
			}
		}
	}
}

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


	bfs_solution(n, m, arr, check);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%c", check[i][j]);
		}
		printf("\n");
	}

	return 0;
}
