array = [8,6,5,1,3,5,6,7,1,8]

count = [0] * (max(array) + 1)

for idx in range(len(array)):
	count[array[idx]] += 1

for i in range(len(count)):
	for j in range(count[i]):
		print(i, end = " ")
