#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;
#define MAX 1000

int n;
int emoge = 1;
int check_bfs[MAX * 2 + 1];

void bfs(int target_num)
{
	queue <tuple<int, int, int>> q;
	check_bfs[emoge] = 1;
	q.push({emoge, 0, 0});
	while(!q.empty())
	{
		emoge = get<0>(q.front());
		int clip_bord = get <1> (q.front());
		int	count = get <2> (q.front());
		q.pop();

		// if(emoge == target_num)
		// {
		// 	cout << "touch!! :" << emoge <<" count :" << count << "\n";
		// 	check_bfs[target_num] = 1;
		// 	break;
		// }
		if(emoge > 0) // 복
		{
			count++;
			clip_bord = emoge;
			cout <<"{emoge , clipbord, count} : "<< emoge<< " , " << clip_bord <<" , "<< count <<"\n";
			if(emoge == target_num)
			{
				cout << "touch!! count = " << count << "\n";
				check_bfs[target_num] = 1;
				break;
			}
			q.push({emoge, clip_bord, count});
			check_bfs[emoge] = 1;
		}
		if(emoge + clip_bord <= 1000 && clip_bord > 0) // 붙
		{
			count++;
			emoge += clip_bord;
			cout <<"{emoge , clipbord, count} : "<< emoge<< " , " << clip_bord <<" , "<< count <<"\n";
			if(emoge == target_num)
			{
				cout << "touch!! count = " << count << "\n";
				check_bfs[target_num] = 1;
				break;
			}
			if(check_bfs[emoge] == 1)
				continue;
			q.push({emoge, clip_bord, count});
			check_bfs[emoge] = 1;
		}
		if(emoge - 1 > 1) //잘
		{
			count++;
			emoge --;
			cout <<"{emoge , clipbord, count} : "<< emoge<< " , " << clip_bord <<" , "<< count <<"\n";
			if(emoge == target_num)
			{
				cout << "touch!! count = " << count << "\n";
				check_bfs[target_num] = 1;
				break;
			}

			if(check_bfs[emoge] == 1)
				continue;
			q.push({emoge, clip_bord, count});
			check_bfs[emoge] = 1;
		}

	}
}

int main()
{
	cin >> n;
	bfs(n);
}
