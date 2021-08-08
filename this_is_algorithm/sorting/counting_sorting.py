array = [4, 4, 4, 1, 4]

counting = [0] * (max(array) + 1)

for i in range(len(array)):
	counting[array[i]] += 1

for i in range(len(counting)):
	for j in range(counting[i]):
		print(i, end = " ")


print("\n", array, "\n")
print(counting)
