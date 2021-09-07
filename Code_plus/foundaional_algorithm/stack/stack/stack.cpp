#include <iostream>
// #include <string>

void push(int *stack, int *size, int num)
{
	stack[*size] = num;
	*size = *size + 1;
}

int pop(int *stack, int *size)
{
	int i;

	if (*size == 0)
	{
		return -1;
	}

	i = *size - 1;
	*size -= 1;
	return stack[i];
}

int size(int *size)
{
	return *size;
}

int empty( int *size)
{
	if(*size == 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

int top(int *stack, int *size)
{
	if(*size == 0)
		return -1;
	return stack[*size - 1];
}

int main()
{
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(NULL);
	// std::cout.tie(NULL);

	int num_of_command;
	int num;
	std::string command;
	std::string s_push = "push";
	std::string s_pop = "pop";
	std::string s_empty = "empty";
	std::string s_size = "size";
	std::string s_top = "top";
	int *stack;
	int  stack_size;
	int times;


	std::cin >> num_of_command;
	stack = new int[num_of_command];
	stack_size = 0;
	times = 0;

	while (times < num_of_command)
	{
		std:: cin >> command;
		if(!(command.compare(s_push)))
		{
			std::cin >> num;
			push(stack, &stack_size, num);
		}

		else if(!(command.compare(s_pop)))
		{
			std::cout << pop(stack, &stack_size) << '\n';
		}

		else if(!(command.compare(s_empty)))
		{
			std::cout << empty(&stack_size) << '\n';
		}

		else if(!(command.compare(s_size)))
		{
			std::cout << size(&stack_size) << '\n';
		}

		else if(!(command.compare(s_top)))
		{
			std::cout << top(stack, &stack_size) << '\n';
		}

		times++;
	}

}
