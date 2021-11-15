#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


vector <int> adj_list[3001];// 인접 리스트 // 이중배열 // 내가 간선리스트로 잘못알려줌 ㅈㅅㅈㅅ;;
vector <int> route;
int root_value;
int check[3001];
int preorder[3001];


void print_back_rout(int start_node, int *node_value)
{
	int next = preorder[start_node];
	if(next == -1)
		return;
	cout<< node_value[next];

	print_back_rout(next, node_value);

}

void back_dfs(int cur_node, int depth, int *node_value, int &flag)
{
	int parants = preorder[cur_node];
	if(preorder[cur_node] == -1 && depth - 1 == 0)
	{
		flag = 1;
		// cout << "node_valsue ,routu (" << node_value[cur_node] <<" , "<< route[depth -1]<< ")\n";
		// cout << "depth : " << depth  - 1<< "\n";
	}

	else if(route[depth - 1] == node_value[cur_node])
	{
		// cout <<"node_value , routu ("<<route[depth -1]<< " , " <<node_value[cur_node] << ") \n";
		depth--;
		back_dfs(parants, depth, node_value, flag);
	}
}

void dfs(int cur_node, int pre_node,int *node_value, int depth)
{
	int object_node = route[depth-1];
	if(object_node == node_value[cur_node])
	{
		int flag = 0;
		back_dfs(cur_node, depth, node_value, flag);
		if(flag == 1)
		{
			cout << node_value[cur_node];
			print_back_rout(cur_node, node_value);
		}
	}
	check[cur_node] = 1;
	for(int i = 0; i < (int)adj_list[cur_node].size(); i++)
	{
		int next_node = adj_list[cur_node][i];

		if(check[next_node] == 0)
		{
			preorder[next_node] = cur_node;
			// cout << "next_node : " << next_node << "\n";
			dfs(next_node, cur_node, node_value , depth);
		}
	}

}

int main()
{
	int n; // 노드의 갯수;
	int input_count; // 입력 갯숫
	cin >> n;
	cin >> input_count;
	cin >> root_value;
	while(input_count--)
	{
		int from;
		int to;
		cin >> from >> to;
		 // 양방향 그래프이므로 간선 양방향으로 간선리스트 에 할당.
		adj_list[from].push_back(to);
	}

	int *node_value	= new int[n + 1];
	memset(node_value , 0, sizeof(int) * n + 1);

	for(int i = 1; i <= n; i++)
	{
		int value;
		cin >> value;
		node_value[i] = value;// 노드 순서 대로 값을 입력한다 ex 3 4 5 7 5 5 5
	}

	int count_route;

	cin >> count_route;
	int i = count_route;
	while (i--)
	{
		int route_vlaue;
		cin >> route_vlaue;
		route.push_back(route_vlaue);
	}

	// for(int i = 1; i <= n; i++) // 인접 리스트 출력
	// {
	// 	cout << "i : [" << i << "] [ ";
	// 	for(int j = 0; j < (int)adj_list[i].size(); j++)
	// 	{
	// 		cout << adj_list[i][j] << ", ";
	// 	}
	// 	cout << "]";
	// 	cout <<  "\n";
	// }

	// for(auto loop : route)
	// {
	// 	cout << loop << " ";
	// }
	// cout << "\n";

	preorder[1] = -1;
	dfs(1,-1, node_value, count_route);

	// for(int i = 0; i <= n; i++)
	// {
	// 	cout << "i : "<< i << " checok: "<< check[i];
	// 	cout << "\n";
	// }

	// for(int i = 0; i <= n; i++)
	// {
	// 	cout << "preoredr i: " << i << " : " <<preorder[i];
	// 	cout << "\n";
	// }
}


