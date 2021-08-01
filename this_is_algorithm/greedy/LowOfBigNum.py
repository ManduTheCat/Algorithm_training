def main():

	numOfinput, M, k = map(int, input().split())
	inputlist = list(map(int, input().split()))

	inputlist = inputlist.sort()
	result = int(0)
	i = 0
	j = 0
	inputList_idx = 0

	#  m <= k
	#m is total add time
	# k is mean able add time



	while i < M:

		if j == k:
			result += int(inputlist[inputList_idx -2])
			i += 1
			j = 0

		result += int(inputlist[inputList_idx -1])
		i += 1
		j += 1



if __name__ == "__main__":
	main()
