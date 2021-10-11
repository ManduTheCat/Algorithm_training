#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void out_v (const vector<int> &a, const vector<int> &d, const vector<int> &v, int max_idx)
{
	if(max_idx == -1)
		return ;
	out_v(a, d, v, v[max_idx]);
	cout << a[max_idx] << " ";
}
int main()
{
	int n;
	int max_idx;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n);
	vector<int> v(n);

	for(int i = 0; i < n; i++)
	{
		cin  >> a[i];
	}

	for(int i = 0; i < n; i++)
	{
		d[i] = 1;
		v[i] = -1;
		for(int j = 0; j < i; j++)
		{
			if(a[i] > a[j] && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	cout << *max_element(d.begin(), d.end()) << "\n";
	max_idx = max_element(d.begin(), d.end()) - d.begin();
	out_v(a, d, v, max_idx);
	cout << "\n";
}
