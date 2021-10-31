#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

void bfs(int n, int **&arr, int **&check)
{
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int x = 0;
	int y = 0;
	int count = 1;

	queue <pair<int, int>> q;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			if(check[i][j] == 0 && arr[i][j] == 1)
			{
				q.push(make_pair(i,j));
				while(!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for(int d = 0; d < 4; j++)
					{
						x = x + dx[d];
						y = y + dy[d];
						if(x < n -1 && x > 0 && y < n -1 && y > 0)
						{
							q.push(make_pair(x, y));
							check[x][y] = count;
						}
					}
				}
				count++;
			}
		}
	}
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

	bfs(n , arr, check);
	std::printf("\n");


}
