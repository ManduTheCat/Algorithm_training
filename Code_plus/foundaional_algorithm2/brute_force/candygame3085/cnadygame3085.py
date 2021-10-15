import sys




def main():
	n = int(input())
	arr = list()

	for _ in range(n):
		arr.append(list(map(str,sys.stdin.readline().strip())))

	sub_list = list()
	count_candy = 0
	for i in range(n):
		ch = arr[i][0]
		sub_list = list()
		sub_list.append(ch)

		for j in range(1, n):

			if ch == arr[i][j]:
				sub_list.append(ch)
			else:
				sub_list = list()
				ch = arr[i][j]
				sub_list.append(ch)
		if len(sub_list) > 1:
			count_candy += len(sub_list)

	for i in range(n):
		print(arr[i])
	print(count_candy)


if __name__ == "__main__":
	main()
