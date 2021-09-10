def stack_append(stack_list, input_list):
		i  = 0;
		while(i < len(input_list)):

			if(input_list[i] ==  "("):
				stack_list.append(input_list[i])
			else:
				if(len(stack_list) == 0):
					return 0
				stack_list.pop()
			i+=1

		if(len(stack_list) == 0):
			return 1
		else:
			return 0



def main():

	command_time =int(input())
	j = 0
	while(j < command_time):
		input_list = list(input())
		stack = list()
		if(stack_append(stack,input_list) == 1):
			print("YES")
		else:
			print("NO")
		j+=1

if __name__ == '__main__':
	main()
