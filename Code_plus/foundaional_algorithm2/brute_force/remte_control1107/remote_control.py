import sys


def main():
	n = int(input())
	m = int(input())
	arr_m = [0 for i in range(10)]
	arr_n = list()
	flag = 1

	if m > 0:
		temp = list(map(int,sys.stdin.readline().split()))
		for num in temp:
			arr_m[num] = 1
	while(flag):
		arr_n = list(map(int, str(n)))
		for i in arr_n:
			if arr_m[i] == 1:
				n +=1
				flag = 1
				break
			else:
				flag = 0
	print(n)

if __name__ == "__main__":
	main()
