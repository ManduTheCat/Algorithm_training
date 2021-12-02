//https://excited-hyun.tistory.com/33
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int m;

void dijkstrea(){
	priority_queue <pair<int, int>> pq;
	int dist[100001];

	memset(dist, -1, sizeof(dist));
	pq.push(make_pair(n, 0)); // node, cost;
	dist[n] = 0;// 초기화;

	while(!pq.empty()){
		int cur_node = pq.top().first;
		int cur_cost = -pq.top().second; // 저장할때 -로 pq 로 저장한다 c++ 우선순위 큐는 최대힙이다
		pq.pop();

		if(dist[cur_node] < cur_cost){
			continue;
		}
		for(int i = 0; i < 3; i++){
			int next_node = 0;
			int next_cost = 0;
			if(i == 0){
				next_node = cur_node + 1;
				next_cost = cur_cost + 1;
			}
			else if(i == 1){
				next_node = cur_node - 1;
				next_cost = cur_cost + 1;
			}
			else if(i == 2){
				next_node = cur_node * 2;
				next_cost = cur_cost;
			}

			if(next_node < 0  || next_node > 100000){
				continue;
			}

			if(dist[next_node] == -1 || dist[next_node] >  next_cost){
				dist[next_node] = next_cost;
				pq.push(make_pair(next_node, -next_cost));
			}
		}
	}
	printf("output : %d\n", dist[m]);
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	dijkstrea();
}
