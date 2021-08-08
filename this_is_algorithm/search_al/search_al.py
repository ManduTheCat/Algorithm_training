def binary_search(array, target, start, end):

	mid = (start + end)//2

	if start > end:
		return None

	if array[mid] == target:
		return mid

	elif array[mid] > target:
		return  binary_search(array, target, start, mid - 1)

	else :
		return binary_search(array, target ,mid + 1, end)

