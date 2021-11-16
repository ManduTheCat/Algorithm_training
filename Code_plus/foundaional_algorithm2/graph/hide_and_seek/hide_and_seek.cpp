#include <iostream>
#include <vector>

using namespace std;

vector <int> adj_list[1000000];
int check[1000000];
int back_check[1000000];
int parents[1000000];
int n, k;

void back_dfs(int cur_node)
{
	back_check[cur_node] = 1;
	int next_node = parents[cur_node];
	if( next_node == -1)
	{
		return;
	}
	cout << next_node << " ";
	if(back_check[next_node] == 0)
	{
		back_dfs(next_node);
	}


}

void dfs(int cur_node, int target_node)
{
	check[cur_node] = 1;
	if(target_node == cur_node)
	{
		cout << "dumped" << "\n";
		cout << cur_node << " " ;
		check[target_node] = 0;
		back_dfs(cur_node);
	}
	for(int i = 0; i < (int)adj_list[cur_node].size(); i++)
	{
		int next_node = adj_list[cur_node][i];
		if(check[next_node] == 0)
		{
			check[next_node] = 1;
			parents[next_node] = cur_node;
			dfs(next_node, target_node);
		}
	}

}

int main()
{
	cin >> n >> k;
	//n 은 시작지점 k 는 노드 갯수

	if(n < k )
	{
		for(int i = 0 ; i <= k * 2; i++)
		{
			if (i == 0)
			{
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i * 2);
			}
			else
			{
				adj_list[i].push_back(i * 2);
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i - 1);
			}
		}
	}
	else if(n > k)
	{
		for(int i = 0 ; i <= n; i++)
		{
			if (i == 0)
			{
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i * 2);
			}
			else
			{
				adj_list[i].push_back(i * 2);
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i - 1);
			}
		}

	}

	parents[n] = -1;
	dfs(n , k);
	cout << "\n";

	// for(int i = n; i <= k; i++)
	// {
	// 	cout << "[ ";
	// 	for(int j = 0; j < (int)adj_list[i].size(); j++)
	// 	{
	// 		cout << adj_list[i][j] << " ";
	// 	}
	// 	cout <<"]\n";
	// }

	// for(int i = n; i <= k; i++)
	// {
	// 	cout <<  "i =" << i << " [" << check[i] << "] \n";
	// }


}
