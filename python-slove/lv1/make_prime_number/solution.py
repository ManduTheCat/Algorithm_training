import copy
def is_prime(n):
	count = 0
	for i in range(1,n+1):
		if(n % int(i) == 0):
			count+=1
		if count > 2 :
			return False
	return True

def solution(nums):
	path_check = [False] * 3000
	# print(path_check)
	sum = []
	dfs(nums, 3, sum)
	return 0

def dfs(nums, lv, sum_list):
	# print(sum_list)
	if len(sum_list) == 3:
		# print(sum_list)
		return 0
	lv -=1
	cur_node = nums[0]
	sum_list.append(cur_node)
	nums.remove(cur_node)
	print(nums)

	for n in nums:

		appended_sum_list = copy.deepcopy(sum_list)
		appended_sum_list.append(n)
		# print(appended_sum_list)
		dfs(nums, lv, appended_sum_list)






