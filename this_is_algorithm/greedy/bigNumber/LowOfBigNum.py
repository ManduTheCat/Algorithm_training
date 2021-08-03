def main():

	# numOfinput, M, k = map(int, input().split())
	# inputlist = list(map(int, input().split()))
	inputlist = list()
	inputlist = [2,4,5,4,6]
	M = 8
	k = 3
	print(inputlist)
	inputlist.sort()
	result = []
	i = 0
	j = 0
	inputList_idx = 0

	print(type(inputlist))
	#  m <= k
	#m is total add time
	# k is mean able add time



	while i < M:

		if j == k:
			result.append((inputlist[-2]))
			i += 1
			j = 0

		result.append((inputlist[-1]))
		i += 1
		j += 1

	print(result)


if __name__ == "__main__":
	main()
