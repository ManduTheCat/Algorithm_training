<<<<<<< HEAD
def binary_search(array, target, start, end):

	mid = (start + end)//2

	if start > end:
		return None
=======


def binary(array, target, start, end):
	
	mid = (start + end) // 2
>>>>>>> refs/remotes/origin/master

	if array[mid] == target:
		return mid

<<<<<<< HEAD
	elif array[mid] > target:
		return  binary_search(array, target, start, mid - 1)

	else :
		return binary_search(array, target ,mid + 1, end)

=======
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
>>>>>>> refs/remotes/origin/master
