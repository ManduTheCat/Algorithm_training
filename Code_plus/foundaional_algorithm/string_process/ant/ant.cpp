#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

int main()
{
	int first_string_size;
	int second_string_size;
	int sec;
	char c;
	string first_string;
	string second_string;

	cin >> first_string_size;
	cin >> second_string_size;
	cin >> first_string;
	cin >> second_string;
	cin >> sec;

	list <char> first_string_list;
	list <char> second_string_list;

	for(int i = 0; i < first_string_size; i++)
	{	
		c = first_string[i];
		first_string_list.push_back(c);
	}
	reverse(first_string_list.begin(),first_string_list.end());

	for(int i = 0; i < second_string_size; i++)
	{
		c = second_string[i];
		second_string_list.push_back(c);
	}

	c = first_string_list.back();
	list <char>::iterator itor_pos = second_string_list.begin();
	if(sec <= second_string_size)
		for(int i = 0; i < sec; i++)
		{
			itor_pos++;
		}
	else
	{
		itor_pos = second_string_list.end();
		sec = second_string_size;
	}

	while(sec--)
	{
		c = first_string_list.back();
		second_string_list.insert(itor_pos, c);
		itor_pos--;
		itor_pos--;
		first_string_list.pop_back();

	}

	if(1 != first_string_list.empty())
	{
		for(auto loop : first_string_list)
		{
			cout <<loop;
		}
	}
	for(auto loop : second_string_list)
	{
		cout <<loop;
	}
	cout << "\n";

	return 0;

}
