#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;
#define MAX 1000

int n;
int check_bfs[MAX + 1];

bool check_target(int src, int target)
{
	if(src == target)
	{
		check_bfs[src] = 1;
		return true;
	}
	return false;
}

void bfs(int target_num)
{
	queue <tuple<int, int, int>> q;
	q.push({1, 0, 0});
	while(!q.empty())
	{
		int emoge = get<0>(q.front());
		int clip_bord = get <1> (q.front());
		int	count = get <2> (q.front());
		q.pop();
		count++;
		if(emoge > 0) // 복사
		{
			int temp_clip_bord = emoge;
			// cout <<"{emoge , clipbord, count} : "<< emoge<< " , " << clip_bord <<" , "<< count <<"\n";
			if(check_target(emoge, target_num))
			{
				cout << count << "\n";
				break;
			}

			q.push({emoge, temp_clip_bord, count});
			check_bfs[emoge] = 1;
		}
		if(emoge + clip_bord <= 1000 && clip_bord > 0) // 붙이기
		{
			int temp_emoge = emoge + clip_bord;
			// cout <<"{emoge , clipbord, count} : "<< emoge<< " , " << clip_bord <<" , "<< count <<"\n";
			if(check_target(temp_emoge , target_num))
			{
				cout << count << "\n";
				break;
			}

			check_bfs[temp_emoge] = 1;
			q.push({temp_emoge, clip_bord, count});
		}
		if(emoge - 1 > 1) //자르기
		{
			emoge --;
			// cout <<"{emoge , clipbord, count} : "<< emoge<< " , " << clip_bord <<" , "<< count <<"\n";
			if(check_target(emoge, target_num))
			{
				cout << count << "\n";
				break;
			}
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
