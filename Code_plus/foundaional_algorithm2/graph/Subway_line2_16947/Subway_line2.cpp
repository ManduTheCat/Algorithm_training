#include <iostream>
#include <vector>
#include <string.h>

using namespace std;



//https://ongveloper.tistory.com/276 참조
// 트리는 노드r갯수 -1 개의 간선을 가지게 된다. 이점을 이용해보자.
vector <int> adj_list[3001];
int is_in_cycle[3001]; // yes = true, no = false
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

		if(visit_check[next] == 1)
		{

		}
		else
		{

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
