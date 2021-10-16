#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr_len = 9;
	int arr[9];
	int sum  = 0;

	for(int i = 0; i < arr_len; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);

	for(int i = 0; i < arr_len; i ++)
	{
		for(int j = i + 1; j < arr_len; j++)
		{
			if(sum - arr[i] - arr[j] == 100)
			{
				for(int k = 0; k < arr_len; k++)
				{
					if(k == i || k == j)
					{
						continue;
					}
					cout << arr[k] << "\n";
				}
				return 0;
			}
		}
	}


}
