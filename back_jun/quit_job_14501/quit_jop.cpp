#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector <int> res;
vector <int> adj_list[16];
vector <pair<int, int>> schedule[16];

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
		int sec_next = i + 2;
		if((f_next <= n + 1 )&& (sec_next <= n + 1)){
			printf("%d \n",f_next);
			adj_list[i].push_back(f_next);
			adj_list[i].push_back(i+1);
		}
	}

	// int max = *max_element(res.begin(), res.end());
	// printf("%d", max);

	for(int i = 1; i <= 16; i++){
		printf("%d :", i);
		for(int j = 0; j < (int)adj_list[i].size(); j++){
			printf("%d ", adj_list[i][j]);
		}
		printf("\n");
	}
}
