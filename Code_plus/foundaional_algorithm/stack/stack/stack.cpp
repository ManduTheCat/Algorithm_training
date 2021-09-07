#include <iostream>
#include <string>

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
	return stack[*size - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int num_of_command;
	int num;
	std::string command;
	int *stack;
	int  stack_size;

	// std::cin >> num_of_command;
	// std::cin >> command >> num;

	num_of_command = 10;
	stack = new int[num_of_command];
	stack_size = 0;

	push(stack, &stack_size, 12); //1 //0
	std::cout << top(stack, &stack_size) << '\n';
	push(stack, &stack_size, 9);
	std::cout <<top(stack, &stack_size) << '\n'; //2 //1
	push(stack, &stack_size, 8); //size 3 //index 2
	std::cout << top(stack, &stack_size) << '\n';

	std::cout << "pop :" << pop(stack, &stack_size) << '\n'; //size 3 -> 2 index 2
	std::cout << "top :" <<  top(stack, &stack_size) << '\n';
	std::cout << "empty :" << empty(&stack_size) << '\n';
	std::cout << "size :" << size(&stack_size) << '\n';

	std::cout << "pop :" << pop(stack, &stack_size) << '\n'; //size 3 -> 2 index 2
	std::cout << "pop :" << pop(stack, &stack_size) << '\n'; //size 3 -> 2 index 2
	std::cout << "pop :" << pop(stack, &stack_size) << '\n'; //size 3 -> 2 index 2

	std::cout << "empty :" << empty(&stack_size) << '\n';
	std::cout << "size :" << size(&stack_size) << '\n';
}
