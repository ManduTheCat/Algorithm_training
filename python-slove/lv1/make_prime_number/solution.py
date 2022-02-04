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
	# print(path_check)
	dfs(nums, 0 , 0, 0)
	return 0

def dfs(nums, idx, lv_count, sum):
	if lv_count == 3:
		print("sum : ", sum , " lv : ", lv_count)
		print(is_prime(sum))
	
	for i in range(idx, len(nums)):
		dfs(nums, i + 1, lv_count + 1, sum + nums[i])
		# 3번째 숫자일떼 idx 0 은 아에 취급하지 않음? 이미했던숫자라 의미가 


