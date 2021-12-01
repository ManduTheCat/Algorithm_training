#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct _adj_node{
	int node;
	int cost;
}adj_node;

vector <adj_node> adj_list[100004];
bool check[100004];
int node_count;
int max_node;
int max_cost;

void print_adj()
{
	for(int i = 0; i <= node_count; i++)
	{
		for(int j = 0; j < (int)adj_list[i].size(); j++)
		{
			printf("[i, j : %d, %d ] = n : %d, c: %d   ",i, j, adj_list[i][j].node, adj_list[i][j].cost);
		}
		printf("\n");
	}
}

void print_check()
{
	for(int i = 1; i <= node_count; i++)
	{
		printf("%d ", check[i]);
	}
	printf("[max_node, max_cost] %d %d \n", max_node, max_cost);
}

void dfs(int node, int cost)
{
	if(max_cost < cost)
	{
		max_cost = cost;
		max_node = node;
	}
	check[node]= true;
	for(int j = 0; j < (int)adj_list[node].size(); j++ )
		{
			int next_node = adj_list[node][j].node;
			int next_cost = adj_list[node][j].cost;
			if(check[next_node] == false)
			{
				check[next_node] = true;
				dfs(next_node , next_cost + cost);
			}
		}
}

int main()
{
	scanf("%d" , &node_count);
	for(int i = 1; i <= node_count; i++)
	{
		int from;
		scanf("%d" ,&from );
		while(1)
		{
			int count;
			int to;
			scanf("%d", &to);
			if(to == -1)break;
			scanf("%d", &count);
			adj_list[from].push_back({to, count});

		}
	}
	// print_adj();
	dfs(1, 0);
	// print_check();
	memset(check, false, sizeof(check));
	dfs(max_node, 0);
	// print_check();
	printf("%d\n", max_cost);
}

