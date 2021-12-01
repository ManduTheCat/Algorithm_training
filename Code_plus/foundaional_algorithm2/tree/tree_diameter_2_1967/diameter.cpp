#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef struct _node{
	int node;
	int cost;
}node;

vector <node> adj_list[20002];
bool check[10002];
int node_count;
int max_node;
int max_cost;

void dfs(int node, int cost){
	check[node] = true;
	if(max_cost < cost){
		max_cost = cost;
		max_node = node;
	}
	for(int i = 0; i < (int)adj_list[node].size(); i++){
		int next = adj_list[node][i].node;
		int cost_of_next = adj_list[node][i].cost;
		if(check[next] == false){
			check[next] = true;
			dfs(next, cost+cost_of_next);
		}
	}

}

void print_adj(){
	for(int i = 1; i < node_count; i++){
		for(int j = 0; j < (int)adj_list[i].size(); j++){
			printf("[i, j : %d, %d ] = node : %d, cost :  %d     ",i, j, adj_list[i][j].node, adj_list[i][j].cost);
		}
		printf("\n");
	}
}

int main(){
	int from;
	int to;
	int cost;
	scanf("%d", &node_count);
	if(node_count == 1){
		printf("0\n");
		return 0;
	}
	for(int i =  0; i < node_count; i++){
		scanf("%d %d %d",&from, &to, &cost);
		adj_list[from].push_back({to, cost});
		adj_list[to].push_back({from, cost});
	}
	dfs(1, 0);
	memset(check, false, sizeof(check));
	dfs(max_node, 0);
	printf("%d\n", max_cost);

}
