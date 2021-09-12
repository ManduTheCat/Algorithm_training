def main():
	input_str = list(input())
	max_cmd_num = int(input())
	input_list = list(input() for _ in range(max_cmd_num))
	second_stack = list()

	for input_cmd in input_list:
		if len(input_cmd) == 2:
			input_str.append(input_cmd[1])
		else:
			if input_cmd == "L":
				if len(input_str) != 0:
					temp = input_str.pop()
					second_stack.append(temp)
			elif input_cmd == "D":
				if len(second_stack) != 0:
					temp = second_stack.pop()
					input_str.append("temp")
			elif input_cmd == "B":
				input_str.pop()

	print(input_cmd + second_stack)



if __name__ == "__main__":
	main()
