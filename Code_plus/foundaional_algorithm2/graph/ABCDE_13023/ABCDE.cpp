#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool adj_arr[2000][2000]; //인접 관계를 기록하는 인접 행렬
vector <int> adj_list[2000]; // 연결된 정점을 기록하는 인접 리스트
vector <pair<int, int>> edge_list;

int main()
{
	// bool adj_arr[2000][2000]; //인접 관계를 기록하는 인접 행렬
	// vector <int> adj_list[2000]; // 연결된 정점을 기록하는 인접 리스트
	// vector <pair<int, int>> edge_list;


	int n; //vertex
	int m; //edge_nums
	int from;
	int to;
	cin >> n;
	cin >> m;

	for(int i = 0; i < m; i++)
	{
		cin >> from;
		cin >> to;
		edge_list.push_back({from, to});
		edge_list.push_back({to, from}); // 친구 관계는 양방향 그래프이다

		adj_arr[from][to] = adj_arr[to][from] = true;

		adj_list[from].push_back(to);
		adj_list[to].push_back(from);
	}
	 // edge 갯수가 두배되는 이유 : 양방향이기 떄문에 두번씩 비교하는것이가?
	// for(int i = 0; i <  n; i++)
	// {
	// 	for(int j = 0; j < (int)adj_list[i].size(); j++)
	// 	{
	// 		cout << "adj_list " << i << " = " << adj_list[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }


	// cout << "\n";
	for(int i = 0; i < m*2; i++)
	{
		for(int j = 0; j < m*2; j++)
		{
			//a -> b
			int a = edge_list[i].first;
			int b = edge_list[i].second;
			//c -> d
			int c = edge_list[j].first;
			int d = edge_list[j].second;

			if(a == b || a == c || a == d || b == c || b == d || c == d)
			{
				continue ;  // 서로 다를때 까지 찾아라
			}

			if(!adj_arr[b][c])
			{
				continue;
			}

			for(int e : adj_list[d]) // D 랑 연결 되있는 애들 = e 의 후보 들  조회
			{
				if(e == a || e== b || e == c || e == d)
				{
					continue;
				}
				// cout << a << b << c << d <<  e <<"\n";
				cout << 1 << "\n";
				return 0;
			}
		}
	}
	cout << 0 <<"\n";
	return 0;

}
