def main():
	n, m = map(int, input().split())
	bady_list  = [n][m]

	for i in range(0,n):
		bady_list[i] = list(map(int, input().split()))


	print(bady_list)

if __name__ == "__main__":
	main()
