#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
#include <vector>

using namespace std;


void bfs(int n, int m, int **&arr, int **&check, vector <pair<int, int>> start_points)
{
	int x;
	int y;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0 ,0};
	queue <pair<int, int>> q;
	for(int i = 0; i < (int)start_points.size(); i++)
	{
		x = start_points[i].first;
		y = start_points[i].second;
		q.push(make_pair(x, y));
		check[x][y] = 0;
	}

	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int d = 0; d < 4; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(nx >= 0 && ny >= 0 && n > nx && m > ny)
			{
				if(arr[nx][ny] == 0 && check[nx][ny] == -1)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(arr[i][j] == 0 && check[i][j] == -1)
			{
				std::printf("-1\n");
				return;
			}
		}
	}

	std::printf("%d\n", check[x][y]);


}

int main()
{
	int n;
	int m;
	int num;
	vector <pair<int, int>> start_points;
	scanf("%d %d", &m,&n);

	int **arr = new int*[n];
	int **check = new int*[n];

	for(int i = 0; i < n;  i++)
	{
		arr[i] = new int [m];
		check[i] = new int [m];
	}

	for(int i = 0; i < n; i++)
	{
		memset(check[i], -1, sizeof(int) * m);
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &num);
			arr[i][j] = num;
			if(num == 1)
			{
				start_points.push_back(make_pair(i,j));
			}
		}
	}

	bfs(n, m, arr, check, start_points);

	//배열들 확인용

// 	for(int i = 0; i < n; i++)
// 	{
// 		for(int j = 0; j < m; j++)
// 		{
// 			std::printf("%d ", arr[i][j]);
// 		}
// 		std::printf("\n");
// 	}

// 	std::printf("\n");
// 	for(int i = 0; i < n; i++)
// 	{
// 		for(int j = 0; j < m; j++)
// 		{
// 			std::printf("%d ", check[i][j]);
// 		}
// 		std::printf("\n");
// 	}
}
