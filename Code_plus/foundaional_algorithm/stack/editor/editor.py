from sys import stdin

def main():
	first_stack = list(stdin.readline().strip())
	max_cmd_num = int(input())
	input_list = list()
	for _ in range(max_cmd_num):
		input_list.append(stdin.readline().strip())
	second_stack = list()

	for input_cmd in input_list:
		if len(input_cmd) != 1:
			first_stack.append(input_cmd[-1])
		else:
			if input_cmd == "L":
				if len(first_stack) != 0:
					temp = first_stack.pop()
					second_stack.append(temp)
			elif input_cmd == "D":
				if len(second_stack) != 0:
					temp = second_stack.pop()
					first_stack.append(temp)
			elif input_cmd == "B":
				if len(first_stack) != 0:
					first_stack.pop()

	# print(first_stack ,second_stack)


	for charc in first_stack:
		print(charc, end = "")
	for charc in reversed (second_stack):
		print(charc, end = "")


if __name__ == "__main__":
	main()
