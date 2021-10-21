#include <iostream>

using namespace std;

int main()
{
	int shapes[19][4][2] = {{{0, 1},{1, 1},{2, 1},{2, 0}}, {{0, 0},{0, 1},{0, 2},{1, 2}}, {{0, 0},{0 ,1},{1, 0},{2, 0}},
	{{0, 0},{1, 0},{1, 1},{1, 2}}, {{0, 0},{1, 0},{2, 0},{2, 1}}, {{0, 0},{0, 1},{0, 2},{1, 0}}, {{0, 0}, {0, 1}, {1, 1}, {2, 1}}, {{1, 0},{1, 1},{1, 2},{0, 2}}, //l_shapes
	{{0,0},{1,0},{1,1},{2,1}}, {{1, 0},{1, 1},{0, 1},{0 ,2}}, {{2, 0},{1, 0},{1, 1},{0, 1}}, {{0,0},{0,1},{1,1},{1,2}}, //s_shapes
	{{0,0},{0,1},{0,2},{1,1}}, {{0,1},{1,0},{1,1},{2,1}}, {{1,0},{1,1},{1,2},{0,1}}, {{0,0},{1,0},{2,0},{1,1}}, // t_shapes
	{{0, 0},{1, 0},{2, 0},{3, 0}}, {{0, 0},{0, 1},{0, 2},{0, 3}}, // i_shapes
	{{0, 0},{0, 1},{1, 0},{1, 1}}}; // o_shapes

	int n;
	int m;

	cin >> n;
	cin >> m;

	int **papar = new int *[n];
	for(int i = 0; i < m; i++)
	{
		papar[i] = new int[m];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >>  papar[i][j];
		}
	}

	int sum = 0;
	int res = 0;
	for(int add_n = 0; add_n < n; add_n++)
	{
		for(int add_m = 0; add_m < m; add_m++)
		{
			for(int i = 0; i < 15; i++)
			{
				for(int j  = 0; j < 4; j++)
				{
					cout << "i : " << i << ", " << "\n";
					int x = shapes[i][j][0];
					int y = shapes[i][j][1];
					sum += papar[x + add_n][y + add_m]; // 여기서 증가 감소 필터링 해야한다
					cout << "x , y: " << "(" << x << " + " << add_n<<" , " << y <<" + "<<add_m<<")" << "\n";
					cout <<"papar : "<< papar[x + add_n][y + add_m] << " \n";
				}
				res = max(res, sum);
				sum =0;
				cout <<"res : " << res << "\n";
				cout << " ---------------------------- " << "\n";
			}
		}
	}

	cout << res << "\n";


}
