#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	int first_string_size;
	int second_string_size;
	int sec;
	char c;

	cin >> first_string_size;
	cin >> second_string_size;
	cin >> sec;

	list <char> first_string;
	list <char> second_string;

	for(int i = 0; i < first_string_size; i++)
	{
		cin >> c;
		first_string.push_back(c);
	}
	reverse(first_string.begin(),first_string.end());

	for(int i = 0; i < second_string_size; i++)
	{
		cin >> c;
		second_string.push_back(c);
	}

	c = first_string.back();
	list <char>::iterator itor_pos = second_string.begin();

	for(int i = 0; i < sec; i++)
	{
		itor_pos++;
	}

	while(sec--)
	{
		c = first_string.back();
		second_string.insert(itor_pos, c);
		itor_pos--;
		first_string.pop_back();

	}
	for(auto loop : first_string)
	{
		cout <<loop << " ";
	}
	cout << "\n";

	for(auto loop : second_string)
	{
		cout <<loop << " ";
	}
	cout << "\n";


}
