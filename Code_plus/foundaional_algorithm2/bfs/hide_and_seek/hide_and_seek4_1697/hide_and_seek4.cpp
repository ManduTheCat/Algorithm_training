#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 400000
vector <int> adj_list[MAX * 3 + 1];
queue <int> res;
int check_bfs[MAX * 3 + 1];
int befor_node[MAX * 3 + 1];
int n;
int k;
int count;

void back_print(int start_node)
{
	count++;
	int cur_node = befor_node[start_node];
	if(start_node == n)
	{
		return;
	}
	back_print(cur_node);
	res.push(cur_node);
}

void bfs(int start_node)
{
	queue <int> q;
	check_bfs[start_node] = 1;
	q.push(start_node);

	while(!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		for(int i = 0; i < (int)adj_list[cur_node].size(); i++)
		{
			int next = adj_list[cur_node][i];
			if(check_bfs[next] == 0)
			{
				q.push(next);
				check_bfs[next] = 1;
				befor_node[next] = cur_node;
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n,&k);
	if(n < k)
	{
		for(int i = 0; i<= k * 2; i++)
		{
			if(i > 0)
			{
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i * 2);
				adj_list[i].push_back(i - 1);
			}
			else
			{
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i * 2);
			}
		}
	}
	else
	{
		for(int i = 0; i<= n * 2; i++)
		{
			if(i > 0)
			{
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i * 2);
				adj_list[i].push_back(i - 1);
			}
			else
			{
				adj_list[i].push_back(i + 1);
				adj_list[i].push_back(i * 2);
			}
		}
	}
	bfs(n);
	back_print(k);
	cout << count - 1 << "\n";
	while(!res.empty())
	{
		cout << res.front() << " ";
		res.pop();
	}
	cout << k;
}
