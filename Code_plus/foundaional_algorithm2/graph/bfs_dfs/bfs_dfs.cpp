#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>


using namespace std;
vector <int> adj_list[1001];

int check[1001];



void bfs(int vertex)
{
	queue <int> q;
	memset(check, 0, sizeof(check));
	q.push(vertex);
	check[vertex] = 1;
	while(q.empty() != 1)
	{
		int node = q.front();
		q.pop();
		cout << node << " ";

		for(int i = 0; i < (int)adj_list[node].size(); i++)
		{
			int next = adj_list[node][i];
			if(check[adj_list[next][i]] == 0)
			{
				check[adj_list[next][i]] = 1;
				q.push(adj_list[next][i]);
			}
		}
	}
}

int main()
{
	int vertex, edge, start;
	cin >> vertex >> edge >> start;

	for (int i = 0; i < edge; i++)
	{
		int from;
		int to;
		cin >> from >> to;
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}
	for(int i = 1; i <= vertex; i++)
	{
		sort(adj_list[i].begin(), adj_list[i].end());
	}

	bfs(start);
}
