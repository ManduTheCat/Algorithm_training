def main():

	numOfinput, M, k = map(int, input().split())
	inputlist = list(map(int, input().split()))

	inputlist.sort()
	result = list()
	i = 0
	j = 0
	inputList_idx = 0

	#  m <= k
	#m is total add time
	# k is mean able add time



	while i < M:

		if j == k:
			result.append(int(inputlist[inputList_idx - 2]))
			i += 1
			j = 0
		
		if i == M:
			break

		result.append(int(inputlist[inputList_idx - 1]))
		i += 1
		j += 1

	print(result)


if __name__ == "__main__":
	main()
