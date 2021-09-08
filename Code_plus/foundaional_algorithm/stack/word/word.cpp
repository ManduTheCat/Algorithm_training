#include <iostream>
#include <stack>
#include <string>
#include <string.h>


void see_all_stack(std::stack<char> s)
{
	while(!(s.empty()))
	{
		std::cout << s.top();
		s.pop();
	}
}
int main()
{
	std::stack <char> s;
	std::string input;
	int i;
	char dil;

	dil = ' ';
	getline(std::cin, input);
	i = 0;

	while(i < (int)input.length())
	{
		s.push(input[i]);
		if (input[i] == dil)
		{
			see_all_stack(s);
		}


		i++;
	}
}
