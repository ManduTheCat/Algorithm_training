#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector <int> adj_list[1001];
int check[1001];

void dfs(int start_v)
{

	check[start_v] = 1;
	cout << start_v <<" ";
	for(int i = 0; i <(int)adj_list[start_v].size(); i++)
	{
		// int next = adj_list[start_v][i];
		if(check[adj_list[start_v][i]] == 0)
		{

			dfs(adj_list[start_v][i]);
			// dfs(next);
		}
	}

}

void bfs(int start_v)
{
	queue <int> q;
	memset(check, 0, sizeof(check));
	check[start_v] = 1;
	q.push(start_v);

	while(!q.empty())
	{
		int cur_vertex;
		cur_vertex = q.front();
		cout << cur_vertex << " ";
		q.pop();
		for(int i = 0; i <(int)adj_list[cur_vertex].size(); i++)
		{
			if(check[adj_list[cur_vertex][i]] == 0)
			{
				check[adj_list[cur_vertex][i]] = 1;
				q.push(adj_list[cur_vertex][i]);
			}
		}
	}
}

int main()
{
	int n;
	int m;
	int start_v;
	cin >> n >> m >> start_v;
	for(int i = 0; i < m; i++)
	{
		int from;
		int to;
		cin >> from >> to;
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}
	for(int i = 1; i <= n; i++)
	{
		sort(adj_list[i].begin(), adj_list[i].end());
	}

	bfs(start_v);
	memset(check, 0 , sizeof(check));
	cout <<" \n";
	dfs(start_v);
}
