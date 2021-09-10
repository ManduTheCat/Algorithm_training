#include<iostream>
#include<stack>

using namespace std;


int main()
{
	int n;
	string ans;
	stack<int> s;

	cin >> n;
	int m = 0;

	while(n--)
	{
		int x;
		cin >> x; //input num

		if(x > m) //stack_num
		{
			while (x > m)
			{
				m++;
				s.push(m);
				ans += '+';
			}

			s.pop();
			ans+='-';
		}

		else
		{
			bool found = false;

			if (!s.empty())
			{
				int top = s.top();
				s.pop();
				ans += '-';
				if(x == top)
				{
					found = true;
				}
			}
			if(!found)
			{
				cout << "NO" <<'\n';
				return 0;
			}
		}

	}
	for(auto x : ans)
	{
		cout << x << '\n';
	}
	return 0;
}
