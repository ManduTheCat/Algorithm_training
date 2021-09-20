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
	queue <int>out_put_q;

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
			j++;
		}
		out_put_q.push(q.front());
		q.pop();
		i++;
	}
	
	cout << "<";
	while(!(out_put_q.empty()))
	{
		if(out_put_q.size() == 1)
		{
			cout << out_put_q.front();
			cout << ">" << "\n";
			break;
		}
		cout << out_put_q.front() << ", "; 
		out_put_q.pop();
	}

}
