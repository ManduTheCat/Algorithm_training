import math
pr_count = 0

def eratos(n):
	array = [True for i in range(n + 1)]
	for i in range(2, int(math.sqrt(n) + 1)):
		j = 2
		while i * j <= n:
			array[i * j] = False
			j += 1
	return array[n]

def solution(nums):
	global pr_count
	pr_count = 0
	dfs(nums, 0 , 0, 0)
	print(pr_count)
	return pr_count

def dfs(nums, idx, lv_count, sum):
	global pr_count
	if lv_count == 3:
		if eratos(sum):
			pr_count+=1
			return	None

	for i in range(idx, len(nums)):
		dfs(nums, i + 1, lv_count + 1, sum + nums[i])


