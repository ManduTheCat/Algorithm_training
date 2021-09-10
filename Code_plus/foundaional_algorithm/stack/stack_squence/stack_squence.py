def main():
	max_cmd_num = int(input())
	count = 0
	input_num = int(input())
	stack = list()
	stack_num = 1
	ans_list = list()

	stack.append(stack_num)

	while(count < max_cmd_num):
		if(len(stack) == 0):
			stack.append(1)

		if(stack[-1] == input_num):
			# print("-")
			ans_list.append("-")
			count += 1

			if(not(count < max_cmd_num)):
				break

			stack.pop()
			input_num = int(input())

		elif(stack[-1] < input_num):
			# print("+")
			ans_list.append("+")
			stack_num+=1
			stack.append(stack_num)
			if(input_num < stack_num):
				# print("NO")
				ans_list.append(-1)
				if(not(count < max_cmd_num)):
					break

		elif(stack[-1] > input_num):
			# print("-")
			stack.pop()


	if(-1 in stack):
		print("NO")

	else:
		for i in  range(len(ans_list)):
			print(ans_list[i])



if(__name__ == "__main__"):
	main()
