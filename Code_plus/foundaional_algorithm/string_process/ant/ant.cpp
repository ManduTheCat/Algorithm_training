#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int first_string_size;
	int second_string_size;

	cin >> first_string_size;
	cin >> second_string_size;

	vector<char> first_string(first_string_size * 2, '_');
	vector<char> second_string(second_string_size * 2, '_');

	for(int i = 1; i <= first_string.size(); i+=2)
	{
		cin >> first_string[i];
	}
}
