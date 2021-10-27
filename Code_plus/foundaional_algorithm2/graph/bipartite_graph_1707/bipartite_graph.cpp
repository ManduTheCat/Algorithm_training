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
		cout << cur_v <<" ";
		q.pop();
		for(int i = 0; i < (int)adj_list[cur_v].size(); i++)
		{
			int next_v = adj_list[cur_v][i];
			if(color[next_v] == 0)
			{
				q.push(next_v);
				color[next_v] = 3 - color_num;
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
		for(int i = 0; i < n; i++)
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

		bfs(1,1);
	}



}
