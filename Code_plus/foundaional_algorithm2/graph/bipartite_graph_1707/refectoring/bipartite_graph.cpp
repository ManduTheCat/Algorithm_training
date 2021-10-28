#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector <int> adj_list[20001];
int check[20001];
int n;
int t;
int m;

void bfs(int vertex)
{
	queue <int> q;
	int red = 1;
	int blue = 2;
	int color;
	check[vertex] = red;
	q.push(vertex);

	while(!q.empty())
	{
		int cur_v;
		cur_v = q.front();
		q.pop();

		if(check[cur_v] == red)
			color = blue;
		else if(check[cur_v] == blue)
			color = red;

		for (int i = 0; i < (int)adj_list[cur_v].size(); i++)
		{
			int next_v;
			next_v = adj_list[cur_v][i];
			if(check[next_v] == 0)
			{
				q.push(next_v);
				check[next_v] = color;
			}
		}
	}
}

int main()
{
	cin >> t;


	while(t--)
	{
		cin >> n;
		cin >> m;

		int is_partite_graph  = 1;
		memset(check, 0, sizeof(check));

		for (int i = 0; i <= n; i++)
		{
			adj_list[i].clear();
		}

		for(int i = 0; i < m; i++)
		{
			int from;
			int to;
			cin  >> from;
			cin  >> to;
			adj_list[from].push_back(to);
			adj_list[to].push_back(from);
		}

		for(int i = 1; i <= n; i++)
		{
			if(check[i] == 0)
			{
				bfs(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for(int j = 0; j < (int)adj_list[i].size(); j++)
			{
				if(check[i] == check[adj_list[i][j]])
				{
					is_partite_graph = 0;
				}
			}
		}
		if(is_partite_graph == 1)
		{
			cout << "YES" << "\n";
		}
		else if(is_partite_graph == 0)
		{
			cout << "NO" << "\n";
		}

	}
}
