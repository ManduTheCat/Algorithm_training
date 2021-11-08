#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector <int> adj_list[51];

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
