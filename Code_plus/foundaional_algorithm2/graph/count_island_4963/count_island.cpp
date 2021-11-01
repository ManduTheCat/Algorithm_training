#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;


void bfs(int w, int h, int **&arr, int **&check)
{
	int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
	int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
	int count = 0;
	queue <pair<int, int>> q;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if(arr[i][j] == 1 && check[i][j] == 0)
			{
				count++;
				q.push(make_pair(i, j));
				check[i][j] = count;
				while(!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int d = 0; d < 8; d++)
					{
						int nx = x + dx[d];
						int ny = y + dy[d];
						if(nx < h && nx >= 0 && ny < w && ny >=0 && arr[nx][ny] == 1 && check[nx][ny] == 0)
						{
							q.push(make_pair(nx, ny));
							check[nx][ny] = count;
						}
					}
				}
			}
		}
	}
	printf("%d \n", count);
}

int main()
{
	int w;
	int h;
	while(1)
	{
		scanf("%d %d", &w, &h);

		if(w == 0 &&  h == 0)
		{
			break;
		}

		int **arr = new int*[h];
		int **check = new int*[h];

		for(int i = 0; i < h; i++)
		{
			arr[i] = new int[w];
			check[i] = new int[w];
		}

		for(int i = 0; i < h; i++)
		{
			memset(check[i] , 0 , sizeof(int) * w);
			for(int j = 0; j < w; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		bfs(w, h, arr, check);
		// for(int i = 0; i < h; i++)
		// {
		// 	for(int j = 0; j < w; j++)
		// 	{
		// 		printf("%d", check[i][j]);
		// 	}
		// 	printf("\n");
		// }
	}
}
