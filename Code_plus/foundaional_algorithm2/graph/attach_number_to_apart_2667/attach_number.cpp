#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;


void bfs(int n, int **&arr, int **&check)
{
	queue <pair<int, int>> q;
	int x = 0;
	int y = 0;

	q.push(make_pair(x,y));
	while(!q.empty())
	{	
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d" ,arr[i][j]);
			}
			printf("\n");
		}

		printf("\n");

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%d" ,check[i][j]);
			}
			printf("\n");
		}
	}

}


int main()
{
	int n;
	cin >> n;
	int **arr = new int *[n];
	int **check = new int*[n];
	for (int i  = 0; i < n; i++)
	{
		arr[i] = new int [n];
		check[i] = new int [n];
	}
	for(int i = 0; i < n; i++)
	{
		memset(check[i] , 0 , sizeof(int)*n);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]); // 입력이 연속적일때 하나씩으로 분리하는 방법
		}
	}

	bfs(n , arr, check);
	printf("\n");


}
