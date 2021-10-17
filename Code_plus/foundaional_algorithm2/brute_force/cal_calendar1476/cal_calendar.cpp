#include <iostream>

using namespace std;

int main()
{
	int E;
	int	S;
	int M;

	cin >> E;
	cin >> S;
	cin >> M;

	int e = 0;
	int s = 0;
	int m = 0;

	for(int i = 0; ; i++)
	{
		if(e == E && s == S && m == M)
		{
			cout << i <<"\n";
			return 0;
		}

		e++;
		s++;
		m++;
		if(e == 16)
			e = 1;
		if(s == 29)
			s = 1;
		if(m  == 20)
			m = 1;
	}

}
