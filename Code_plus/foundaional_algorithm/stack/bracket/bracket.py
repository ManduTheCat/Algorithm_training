def main():
	input_list = ['(',')','(',')']
	stack = list()
	i = 0

	while(i < len(input_list)):

		if(input_list[i] ==  "("):
			stack.append(input_list[i])
		else:
			stack.pop()
		i+=1

	if(len(stack) == 0):
		print('yes')
	else:
		print('no')

if __name__ == '__main__':
	main()
