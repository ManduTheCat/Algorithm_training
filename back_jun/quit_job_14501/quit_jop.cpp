#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
vector <int> res;
vector <int> adj_list[16];
vector <pair<int, int>> schedule[16];
bool check[16];

void dfs(int start_node){
	// int p = schedule[start_node][0].second;
	check[start_node] = true;
	for(int i = 0; i < (int)adj_list[start_node].size(); i++){
		int next = adj_list[start_node][i];
		if(check[next] == false){
			dfs(next);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int t;
		int p;
		scanf("%d %d", &t, &p);
		schedule[i].push_back(make_pair(t,p));
	}
	schedule[n+1].push_back(make_pair(0,0));

	for(int i = 1; i <= n ; i++){
		int t = schedule[i][0].first;
		int f_next = i + t;
		if(f_next <= n + 1 ){
			adj_list[i].push_back(f_next);
			for(int j = 1; j + i <= n + 1; j++){
				int s_next = i + j;
				adj_list[i].push_back(s_next);
			}
		}
	}

	for(int i = 1; i <= 16; i++){
		printf("%d :", i);
		for(int j = 0; j < (int)adj_list[i].size(); j++){
			printf("%d ", adj_list[i][j]);
		}
		printf("\n");
	}
	for(int i = 1;  i <= n; i++){
		memset(check, 0, sizeof(check));
		dfs(i);
	}

	for(int i = 0; i<= 16; i++){
		printf("{%d %d} ",i, check[i]);
	}
	printf("\n");
}
