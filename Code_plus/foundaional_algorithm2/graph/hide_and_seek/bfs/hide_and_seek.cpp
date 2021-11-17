#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> adj_list[1000000];
vector <int> parants[1000000];
vector <int> res;
int dfs_check[1000000];
int bfs_check[1000000];
int n,k;

void back_print(int start_node)
{
	dfs_check[start_node] = 1;
	res.push_back(start_node);

	for(int i = 0; i < (int)parants[start_node].size(); i++)
	{
		int cur_node = parants[start_node][i];
		if(dfs_check[cur_node] == 0)
		{
			dfs_check[cur_node] = 1;
			back_print(cur_node);
		}
	}

}

void bfs(int start_node)
{
	queue <int> q;
	bfs_check[start_node] = 1;
	q.push(start_node);

	while(!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		for(int i = 0; i < (int)adj_list[cur_node].size(); i++)
		{
			int next_node = adj_list[cur_node][i];
			if(bfs_check[next_node] == 0)
			{
				parants[next_node].push_back(cur_node);
				bfs_check[next_node] = 1;
				q.push(next_node);
			}

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
	bfs(n);
	back_print(k);
	int count = 0;
	for(auto loop : res)
	{
		count++;
		// cout << loop << " ";
	}
	cout<< count - 1<< "\n";

	// for(int i = 0; i <= k *2; i++)
	// {
	// 	for(int j = 0; j < (int)parants[i].size(); j++)
	// 	{
	// 		cout  << "i : "<< i << " : "<< parants[i][j] <<" ";
	// 	}
	// 	cout << "\n";
	// }
}
