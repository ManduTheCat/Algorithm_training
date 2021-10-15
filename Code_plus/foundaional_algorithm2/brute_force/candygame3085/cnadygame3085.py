import sys

def check(arr):
	len_arr = len(arr)
	ans = 1
	for i in range(len_arr):
		count = 1
		for j in range(1, len_arr):
			if arr[i][j] == arr[i][j - 1]:
				count+=1
			else:
				count = 1
			if count > ans:
				ans = count
		count = 1
		for k in range(1, len_arr):
			if arr[k][i] == arr[k - 1][i]:
				count +=1
			else:
				count = 1
			if count > ans:
				ans = count
	return ans;


def main():
	n = int(input())
	arr = list()
	for _ in range(n):
		arr.append(list(map(str,sys.stdin.readline().strip())))

	for i in range(n):
		print(arr[i])


if __name__ == "__main__":
	main()
