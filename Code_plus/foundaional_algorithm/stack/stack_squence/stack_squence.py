def main():
	max_cmd_num = int(input())
	input_list = list()
	count = 0
	stack = list()
	stack_num = 1
	output_list = list()

	stack.append(stack_num)

	while(count < max_cmd_num):
		input_num = input()
		input_list.append(input_num)
		count +=1

	count = 0
	while(count < len(input_list)):
		print(input_list[count])

		if(len(stack) == 0):
			stack.append(1)

		if(stack[-1] == int(input_list[count])):
			stack.pop()
			output_list.append("-")
			count +=1

		elif(stack[-1] < int(input_list[count])):
			stack_num+=1
			stack.append(stack_num)
			output_list.append("+")

		elif(stack[-1] > int(input_list[count])): #뺏는 대 아니면 없는거다
			stack.pop()
			output_list.append("-")
	print(output_list)


if(__name__== "__main__"):
	main()
