#include <iostream>
#include <queue>

using namespace std;
int main()
{
	int n;
	int k;
	int i;
	int j;
	queue <int>q;

	cin >> n >> k;
	i = 0;
	while(i < n)
	{
		q.push(i + 1);
		i++;
	}

	i = 0;
	while(i < n)
	{
		j =0;
		while(j < k - 1)
		{
			q.push(q.front());
			q.pop();
		}
		i++;
	}

}
