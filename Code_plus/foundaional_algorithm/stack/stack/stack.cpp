#include <iostream>
#include <string>

void push(int *stack, int *size, int num)
{
	stack[*size] = num;
	*size = *size + 1;
	std::cout<< "size :" << *size <<'\n';

}

int pop(int *stack, int *size, int num)
{

}

int size()
{

}

int empty()
{

}

int top()
{

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

	push(stack, &stack_size, 12);
	push(stack, &stack_size, 9);
	push(stack, &stack_size, 8);

	std::cout << stack[0] << '\n';
	std::cout << stack[1] << '\n';
	std::cout << stack[2] << '\n';

}
