#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
queue <int> q;
vector <int> adj_list[1001];
int check[1001] = {};

void bfs(int start_v)
{
	check[start_v] = 1;
	q.push(start_v);
	while(!q.empty())
	{
		int new_vertex = q.front();
		// cout << new_vertex << " ";
		q.pop();

		for(int i = 0; i < (int)adj_list[new_vertex].size(); i++)
		{
			int next_vertex = adj_list[new_vertex][i];
			if(check[next_vertex] == 0)
			{
				check[next_vertex] = 1;
				q.push(next_vertex);
			}
		}
	}
}

int main()
{
	int count = 0;
	int n;
	int m;

	cin >> n;
	cin >> m;

	for(int i = 0; i< m; i++)
	{
		int from;
		int to;
		//방향이 없다 = 양방향 그래프 이다
		cin >> from;
		cin >> to;

		adj_list[from].push_back(to);
		adj_list[to].push_back(from);

	}
	memset(check , 0 , sizeof(check));
	for(int i = 1;  i <= n; i++)
	{
		if(check[i] != 1)
		{
			bfs(i);
			count++;
			// cout << "\n";
		}
	}
	cout << count <<"\n";

}
