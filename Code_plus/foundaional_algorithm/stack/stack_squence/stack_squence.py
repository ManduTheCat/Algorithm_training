def main():
	max_cmd_num =  int(input())
	input_num_list = [int(input()) for _ in range(max_cmd_num)]
	max_num = 0
	stack = list()
	output = list()

	for input_num in input_num_list:
		if max_num < input_num:
			while max_num < input_num:
				max_num+=1
				stack.append(max_num)
				output.append("+")
			stack.pop()
			output.append("-")
		else:
			if stack[-1] != input_num:
				print("NO")
				return 0
			stack.pop()
			output.append("-")

	for symble in output:
		print(symble , end="\n")


if(__name__ == "__main__"):
	main()
