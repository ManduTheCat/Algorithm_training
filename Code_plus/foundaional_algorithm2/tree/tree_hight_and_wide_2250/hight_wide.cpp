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

node adj_list[10001];
int input_times[10001];
int depth_arr[10001];
int r_wide_dot_arr[10001];
int l_wide_dot_arr[10001];
int order;
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
	order++;
	adj_list[node].wide_dot = order;
	// cout << adj_list[node].wide_dot << " ";
	adj_list[adj_list[node].right].depth = adj_list[node].depth + 1;
	inorder(adj_list[node].right);
}


void find_max()
{
	int max_depth = 0;

	for(int i = 1; i <= node_input_times; i++)
	{
		int depth = adj_list[i].depth;
		int order = adj_list[i].wide_dot;
		if(l_wide_dot_arr[depth] == 0)
		{
			l_wide_dot_arr[depth] = order;
		}
		else
		{
			l_wide_dot_arr[depth] = min(l_wide_dot_arr[depth], order);
		}
		r_wide_dot_arr[depth] = max(r_wide_dot_arr[depth], order);
		max_depth = max(max_depth, depth);
	}

	int ans = 0;
	int ans_lev = 0;
	for(int i =1; i <=max_depth; i++)
	{
		if(ans < r_wide_dot_arr[i] - l_wide_dot_arr[i] + 1)
		{
			ans = r_wide_dot_arr[i] - l_wide_dot_arr[i] + 1;
			ans_lev = i;
		}
	}
	cout << ans_lev  << " "  << ans<< "\n";
}

int main()
{

	int root = 0;
	cin >> node_input_times;

	for(int i = 0; i < node_input_times; i++)
	{
		int r, l, root;
		cin >> root >> l >> r;
		adj_list[root].left = l;
		adj_list[root].right = r;
		if(r != -1)input_times[r]++;
		if(l != -1)input_times[l]++;
	}
	for(int i = 1; i < node_input_times; i++) //루트를찾는 방법 한번만 등장하면 루트다
	{
		if(input_times[i] == 0)
		{
			root = i;
		}
	}
	adj_list[root].depth = 1;
	inorder(root); // root is not must 1!!!
	find_max();
}
