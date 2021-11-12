#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//https://ongveloper.tistory.com/276 참조
// 사이클 을 찾기 위한 조건 : 백엣지
// 백엣지 조건
// 1. 노드의 부모노드 != 자식노드 이유는 양방향 그래프에서는 무조건 이전 노드 로 갈수 있는 엣지 가 있다.
// 그래서 단순 하게 바로 뒤로 가는 엣지의 경우는 무시해야한다
// 2. 노드의 자식 노드가 dfs 탐색중 방문을 했던 노드

vector <int> adj_list[3001];
int cycle_node_list[3001];
int visit_bfs[3001];
int parants_vertex[3001];
int flag_cycle;

void find_circle(int cur_vertex)
{
	visit_bfs[cur_vertex] = 1;
	for(int i = 0; i < (int)adj_list[cur_vertex].size(); i++)
	{
		if(flag_cycle == 1)
			return;
		int next = adj_list[cur_vertex][i];
		int parants = parants_vertex[cur_vertex];

		if(visit_bfs[next] == 1) // 탐색중 방문 했던 노드
		{
			if(parants != next) // 부모노드와 자식노드가 다르다
			{
				flag_cycle = 1;
				cycle_node_list[cur_vertex] = 1;
				while(cur_vertex != next)
				{
					cycle_node_list[parants_vertex[cur_vertex]] = 1;
					cur_vertex = parants_vertex[cur_vertex];
				}
				return;
			}
		}
		else
		{
			parants_vertex[next] = cur_vertex;
			find_circle(next);
		}
	}
}

int main()
{
	int vertex_num;
	cin >> vertex_num;
	for(int i = 0; i < vertex_num; i++)
	{
		int from, to;
		cin >> from >> to;
		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}

	find_circle(1);
	for(int i = 1; i <= vertex_num; i++)
	{
		printf("%d",cycle_node_list[i]);
	}
	printf("\n");

}
