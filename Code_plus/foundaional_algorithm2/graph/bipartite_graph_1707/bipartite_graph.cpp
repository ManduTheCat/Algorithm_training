#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
vector <int> adj_list[20001];
int color[20001];

void bfs(int start_v, int color_num)
{
	queue <int> q;
	q.push(start_v);
	color[start_v] = color_num;
	while(!q.empty())
	{
		int cur_v  = q.front();
		// cout << cur_v <<" ";
		q.pop();
		for(int i = 0; i < (int)adj_list[cur_v].size(); i++)
		{
			int next_v = adj_list[cur_v][i];

			// color[next_v] = 3 - color[cur_v]; // 여기에서 컬러를 배정해버리면 이미칠해진 vertex도 칠해진다
			if(color[next_v] == 0)
			{
				q.push(next_v);
				color[next_v] = 3 - color[cur_v]; // 인접 vertex 색과 다른색 칠하기
			}
		}
	}
}

int main()
{
	int k;
	int n;
	int m;
	cin >> k;
	while(k--)
	{
		cin >> n;
		cin >> m;
		// memset(color, 0, sizeof(color));
		// memset(adj_list , 0 , sizeof(adj_list));
		for(int i = 0 ; i <= n; i++)
		{
			adj_list[i].clear();
			color[i] = 0;
		}

		for(int i = 0; i < m; i++)
		{
			int from;
			int to;
			cin >> from;
			cin >> to;
			adj_list[from].push_back(to);
			adj_list[to].push_back(from);
		}

		for(int i  = 1; i <= n; i++)
		{
			if(color[i] == 0)
				bfs(i,1);
		}
		// for(int i = 1; i <= n; i++)
		// {
		// 	cout << color[i] <<" ";
		// }
		// cout << "\n";

	//연결된 vertex 끼리 같은 색이면 안된다


		int flag = 1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < (int)adj_list[i].size(); j++)
			{
				if(color[i] == color[adj_list[i][j]])
				{
					flag = 0;
				}
			}
		}

		if(flag == 1)
			cout << "YES" << "\n";
		else if (flag == 0)
			cout << "NO" << "\n";

	}
	return 0;
}
