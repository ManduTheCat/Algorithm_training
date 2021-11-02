#include <iostream>
#include <queue>
#include <string.h>
#include <utility>

using namespace std;

int n;

void bfs(pair <int, int> start_point, pair <int, int> end_point, int **&arr)
{
	int dx[8] = {1, -1, 1, -1, 2, 2, -2, -2};
	int dy[8] = {2, 2, -2, -2, 1, -1, 1, -1};
	int x;
	int y;
	queue <pair<int, int>> q;

	q.push(start_point);
	x = q.front().first;
	y = q.front().second;
	arr[x][y] = 0;

	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int d = 0; d < 8; d++)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if(0 <= nx && 0 <= ny && nx < n && ny < n && arr[nx][ny] == -1)
			{
				arr[nx][ny] = arr[x][y] + 1;
				q.push(make_pair(nx, ny));
				if(nx == end_point.first && ny == end_point.second)
				{
					printf("%d\n", arr[nx][ny]);
					return;
				}
			}
		}
	}
}

int main()
{
	pair <int, int> start_point;
	pair <int, int> end_point;
	int count_test_case;
	scanf("%d", &count_test_case);

	while(count_test_case--)
	{
		scanf("%d", &n);
		int **arr = new int *[n];

		for(int i = 0; i < n; i++)
		{
			arr[i] = new int [n];
		}

		for(int i = 0; i < n; i++)
		{
			memset(arr[i], -1, sizeof(int) *n);
		}

		scanf("%d %d", &start_point.first, &start_point.second);
		scanf("%d %d", &end_point.first, &end_point.second);
		if(start_point.first == end_point.first && start_point.second == end_point.second)
		{
			printf("0\n");
			continue;
		}
		bfs(start_point, end_point, arr);
	}
}
