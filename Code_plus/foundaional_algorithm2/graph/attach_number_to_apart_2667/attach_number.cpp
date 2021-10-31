#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <utility>
<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/master
using namespace std;


void bfs(int n, int **&arr, int **&check)
{
<<<<<<< HEAD
	queue <pair<int, int>> q;
	int x = 0;
	int y = 0;

	q.push(make_pair(x,y));
	while(!q.empty())
	{	
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d" ,arr[i][j]);
			}
			printf("\n");
		}

		printf("\n");

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d" ,check[i][j]);
			}
			printf("\n");
		}
	}

=======
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	int x;
	int y;
	int count = 0;
	int group_count = 0;

	queue <pair<int, int>> q;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			x = i;
			y = j;
			if(check[i][j] == 0 && arr[i][j] == 1)
			{
				group_count++;
				q.push(make_pair(x,y));
				check[x][y] = group_count;
				while(!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					count ++;
					printf("x: %d,y: %d, count: %d\n", x, y, count);
					for(int d = 0; d < 4; d++)
					{
						int nx;
						int ny;
						nx = x + dx[d];
						ny = y + dy[d];
						if(nx < n && nx >= 0 && ny < n && ny >= 0)
						{
							if(check[nx][ny] == 0 && arr[nx][ny] == 1)
							{
								q.push(make_pair(nx, ny));
								check[nx][ny] = group_count;
							}
						}
					}
				}
			}
		}
	}
>>>>>>> refs/remotes/origin/master
}


int main()
{
	int n;
	cin >> n;
	int **arr = new int *[n];
	int **check = new int*[n];
	for (int i  = 0; i < n; i++)
	{
		arr[i] = new int [n];
		check[i] = new int [n];
	}
	for(int i = 0; i < n; i++)
	{
		memset(check[i] , 0 , sizeof(int)*n);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]); // 입력이 연속적일때 하나씩으로 분리하는 방법
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	bfs(n , arr, check);
	std::printf("\n");

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d", check[i][j]);
		}
		printf("\n");
	}

}
