#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <string.h>
using namespace std;


int main()
{
	int w;
	int h;
	while(1)
	{
		scanf("%d %d", &w, &h);

		if(w == 0 &&  h == 0)
		{
			break;
		}

		int **arr = new int*[h];
		int **check = new int*[h];
		for(int i = 0; i < h; i++)
		{
			arr[i] = new int[w];
			check[i] = new int[w];
		}

		for(int i = 0; i < h; i++)
		{
			memset(check[i] , 0 , sizeof(int) * w);
			for(int j = 0; j < w; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}

		for(int i = 0; i < h;  i++)
		{
			for(int j = 0; j < w; j++)
			{
				printf("%d ", check[i][j]);
			}
			printf("\n");
		}


	}
}
