def main():
	command_times = int(input())

	j = 0;

	while(j < command_times):

		input_str = list(input())
		stack = list()
		output_stack = list()

		input_str.append(' ')
		i = 0
		while(i < len(input_str)):

			stack.append(input_str[i])
			if(input_str[i] == ' '):

				while(len(stack) != 0):
					output_stack.append(stack.pop())

			i+=1

		del output_stack[0]
		print(''.join(output_stack));
		j+=1

if __name__ == "__main__":
	main()
