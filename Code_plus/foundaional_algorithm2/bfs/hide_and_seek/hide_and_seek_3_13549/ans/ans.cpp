#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int cost[100001];
int X[2] = {-1, 1};

priority_queue<pair<int, int>> pq; //비용, 위치

int main(void){
    int n, k;
    int cur_node, cur_cost;
    int next_node, next_time;

    scanf("%d %d", &n, &k);

    for(int i=0; i<100001; i++){
        cost[i] = -1;
    }
    pq.push(make_pair(0, n));
    cost[n] = 0;

    while(!pq.empty()){
        cur_cost = -pq.top().first;
        cur_node = pq.top().second;
        pq.pop();

        if(cost[cur_node] < cur_cost){
            continue;
            }
        for(int i=0; i<3; i++){
            if( i== 2){
                next_node = 2*cur_node;
                next_time = cur_cost;
            }
            else{
                next_node = cur_node+ X[i];
                next_time = cur_cost+1;
            }
            if(next_node < 0 || next_node > 100000)
                continue;

            if(cost[next_node] == -1 || cost[next_node] > next_time){
                cost[next_node] = next_time;
                pq.push(make_pair(-next_time, next_node));
            }
            // else if(cost[next_node] > next_time){
            //     cost[next_node] = next_time;
            //     pq.push(make_pair(-next_time, next_node));
            // }
        }
    }
    printf("%d\n", cost[k]);
}
