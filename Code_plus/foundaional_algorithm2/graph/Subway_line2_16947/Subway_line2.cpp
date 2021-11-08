#include <iostream>
#include <vector>
#include <string.h>

using namespace std;



//https://ongveloper.tistory.com/276 참조
// 트리는 노드r갯수 -1 개의 간선을 가지게 된다. 이점을 이용해보자.
vector <int> adj_list[3001];
int is_cycle_node[3001]; // yes = true, no = false
int visit_check[3001];
int pre_vertex[3001];
int check_status;

void chek_is_circle(int cur_vertex)
{
	visit_check[cur_vertex] = 1;
	for(int i = 0; i < (int)adj_list[cur_vertex].size(); i++)
	{
		if(check_status == 1)
			return;

		int next = adj_list[cur_vertex][i];

		if(visit_check[next] == 1) // 돌다가 방문햇던걸 다시 돌아온다오면
		{
			if(next != pre_vertex[cur_vertex]) //그게 바로 이전것이 아니라면
			{
				check_status = 1;
				is_cycle_node[cur_vertex] = 1;
				while(cur_vertex != next) // 과거 것을 체크 하면서 뒤로 간다;
				{
					is_cycle_node[pre_vertex[cur_vertex]] = 1;
					cur_vertex = pre_vertex[cur_vertex];

				}
				return;
			}

		}
		else
		{
			pre_vertex[next] = cur_vertex; // next 의 이전 vertex 기록
			chek_is_circle(next);

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

}
