#include <iostream>
#include <vector>

using namespace std;

typedef struct _node{
	char right;
	char left;
}node;

vector <node> adj_list(26);

void preorde(char node) // root - left - right; like bfs
{
	if(node == '.')
	{
		return;
	}
	cout << node;
	preorde(adj_list[node].left);
	preorde(adj_list[node].right);
}

void inorder(char node) // left - root - right
{
	if(node == '.')
	{
		return;
	}
	inorder(adj_list[node].left);
	cout << node;
	inorder(adj_list[node].right);


}

void postorder(char node) // left - right - root  leaf first
{
	if(node == '.')
	{
		return;
	}
	postorder(adj_list[node].left);
	postorder(adj_list[node].right);
	cout << node;

}

int main(){
	int node_count;
	cin >> node_count;

	for(int i = 0; i < node_count; i++){
		char root;
		char r;
		char l;

		cin >> root >> l >> r;
		adj_list[root].left = l;
		adj_list[root].right = r;
	}
	preorde('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";
}
