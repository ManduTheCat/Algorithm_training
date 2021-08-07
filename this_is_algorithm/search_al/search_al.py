

def binary(array, target, start, end):
	
	mid = (start + end) // 2

	if array[mid] == target:
		return mid

	if array[mid] < target:
		return binary(array, target, mid + 1, end)
	
	if array[mid] > target:
		return binary(array, target, start , mid - 1)

def main():

	n, target  = map(int, input().split())

	array = list(map(int, input().split()))

	result = binary(array, target, 0, n - 1)

	print(result + 1)

if __name__ == "__main__":
	main()