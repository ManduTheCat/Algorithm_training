#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
using namespace std;

void bfs(int n, int m, int **&arr, int **&check)
{
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0 , 0};
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = 1;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(n > nx && m > ny && nx >= 0 && ny >= 0)
			{
				if(arr[nx][ny] == 1 && check[nx][ny] == 0)
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = check[x][y] + 1; // 각각 탐색이 시작한 곳에서의 누적이 필요
				}
			}
		}
	}
	printf("%d\n", check[n - 1][m - 1]);
}

int main()
{
	int n;
	int m;
	scanf("%d %d", &n, &m);

	int **arr = new int *[n]; // n = x
	int **check = new int *[n];

	for(int i = 0; i < n; i++)
	{
		arr[i] = new int[m]; //m = y;
		check[i] = new int[m];
	}

	for(int i = 0; i < n; i++)
	{
		memset(check[i], 0, sizeof(int) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs(n, m, arr, check);
}
