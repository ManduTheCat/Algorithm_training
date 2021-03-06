import math
pr_count = 0
def is_prime(n):
	for i in range(2,int(math.sqrt(n))+1):
		if(n % int(i) == 0):
			return False
	return True

def solution(nums):
	global pr_count
	pr_count = 0
	dfs(nums, 0 , 0, 0)
	print(pr_count)
	return pr_count

def dfs(nums, idx, lv_count, sum):
	global pr_count
	if lv_count == 3:
		if is_prime(sum):
			pr_count+=1

	for i in range(idx, len(nums)):
		dfs(nums, i + 1, lv_count + 1, sum + nums[i])
