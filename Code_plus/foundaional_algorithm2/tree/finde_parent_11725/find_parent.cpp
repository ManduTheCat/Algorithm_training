#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj_list[100001];
int node_count;
int check[100001];
int parant[100001];

void bfs(int node)
{
	queue <int> q;
	check[node] = 1;
	q.push(node);
	while(!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		for(int i = 0; i < (int)adj_list[cur_node].size(); i++)
		{
			int next_node = adj_list[cur_node][i];
			if(check[next_node] == 0)
			{
				q.push(next_node);
				check[next_node] = 1;
				parant[next_node] = cur_node;
			}
		}
	}

}

int main()
{
	scanf("%d", &node_count);
	for(int i = 0; i <= node_count - 1; i++)
	{
		int from;
		int to;
		scanf("%d %d",&from, &to);
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}
	bfs(1);
	for(int i = 2; i <= node_count; i++)
	{
		printf("%d\n", parant[i]);
	}
}
