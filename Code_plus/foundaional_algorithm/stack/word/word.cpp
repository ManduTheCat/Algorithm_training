#include <iostream>
#include <stack>
#include <string>
#include <string.h>

void show_all(std::stack<int> s)
{
	while(!s.empty())
	{
		std::cout << s.top() << '\n';
		s.pop();
	}
}

int main()
{
	std::string input;
	std::stack<char> s;
	int i;
	char *str_chr;
	char *str_token;

	getline(std::cin, input);
	i = 0;
	str_chr = new char[(int)input.length() * 10];

	while(i < (int)input.length())
	{
		str_chr[i] = input[i];
		i++;
	}

	str_token = strtok(str_chr, " ");

	while(str_token != NULL)
	{
		std::cout << str_token << '\n';
		str_token = strtok(NULL, " ");
	}
}
