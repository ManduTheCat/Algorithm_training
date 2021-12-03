//https://excited-hyun.tistory.com/33
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dist[100001];
int dx[2] = {1, -1};

priority_queue <pair<int, int>>  pq;

int main(){
	int n;
	int k;
	
	int cur_node;
	int cur_cost;
	int next_node;
	int next_cost;

	scanf("%d %d", &n, &k);

	memset(dist, 1000000, sizeof(dist));
	pq.push(make_pair(0, n));
	dist[n] = 0;

	while(!pq.empty()){
		
		cur_cost = -pq.top().first;
		cur_node = pq.top().second;
		pq.pop();

		if(dist[cur_node] < cur_cost)
		{
			continue;
		}
		for(int i = 0; i < 3; i++){
			if(i == 2){
				next_cost = cur_cost;
				next_node = cur_node * 2;
			}
			else{
				next_cost = cur_cost + 1;
				next_node = cur_node + dx[i];
			}
		if(next_node < 0 || next_node > 100000)
			continue;
		
		if(dist[next_node] > next_cost){
			dist[next_node] = next_cost;
			pq.push(make_pair(-next_cost, next_node));
			}
		}
	}
	printf("%d\n", dist[k]);
}