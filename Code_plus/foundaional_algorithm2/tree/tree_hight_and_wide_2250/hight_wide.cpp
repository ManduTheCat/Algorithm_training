#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _node{
	int right;
	int left;
	int depth;
	int wide_dot;
}node;

vector <node> adj_list(10001);
int input_times[10001];
int depth_arr[10001];
int wide_dot_arr[1001];
int wide_input_times;
int node_input_times;


void inorder(int node)
{
	if(node == -1)
	{
		return;
	}

	adj_list[adj_list[node].left].depth = adj_list[node].depth + 1;
	inorder(adj_list[node].left);
	// cout << node << ":";
	wide_input_times++;
	adj_list[node].wide_dot = wide_input_times;
	// cout << adj_list[node].wide_dot << " ";
	adj_list[adj_list[node].right].depth = adj_list[node].depth + 1;
	inorder(adj_list[node].right);
}


void find_max()
{
	int max_res = 0;
	int depth_res = 0;
	for(int i = 0; i < node_input_times; i++)
	{
		depth_arr[i] = adj_list[i].depth;
		wide_dot_arr[i] = adj_list[i].wide_dot;
	}
	for(int i = 1; i <= node_input_times; i++)
	{
		for(int j = i + 1; j <= node_input_times; j++)
		{
			if(adj_list[i].depth == adj_list[j].depth)
			{
				// cout << adj_list[j].wide_dot<< " : " << adj_list[i].wide_dot << " ";
				if(max_res < adj_list[j].wide_dot - adj_list[i].wide_dot)
				{
					max_res = max(adj_list[j].wide_dot - adj_list[i].wide_dot, max_res);
					depth_res = adj_list[i].depth;
				}
				// cout << "\n";

			}
		}
	}
	cout << depth_res+ 1<<" "<< max_res + 1 << "\n";
}

int main()
{

	int root;
	cin >> node_input_times;

	for(int i = 0; i < node_input_times; i++)
	{
		int r, l, root;
		cin >> root >> l >> r;
		adj_list[root].left = l;
		adj_list[root].right = r;
		if(r != -1)input_times[r]++;
		if(l != -1)input_times[l]++;
		if(root != -1)input_times[root]++;
	}
	for(int i = 1; i < node_input_times; i++) //루트를찾는 방법 한번만 등장하면 루트다
	{
		if(input_times[i] == 1)
		{
			root = i;
		}
	}
	inorder(root); // root is not must 1!!!
	find_max();
}
