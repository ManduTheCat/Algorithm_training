#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n;
vector <int> res;
vector <int> adj_list[16];
vector <pair<int, int>> schedule[16];
bool check[16];

void bfs(int start_node){
	queue <int> q;
	// int p = schedule[start_node][0].second;
	q.push(start_node);
	check[start_node] = true;
	while(!q.empty()){
		int cur_node =	q.front(); //1
		q.pop();
		for(int i = 0; i < (int)adj_list[cur_node].size(); i++){
			int next_node = adj_list[cur_node][i];
			if(check[next_node] == false){
				q.push(next_node);
			}

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
			for(int j = i + 1; j + i <= n + 1; j++){
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
		bfs(1);
	}
}
