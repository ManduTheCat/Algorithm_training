def solution(x):
	temp =  x
	sum = 0
	while(temp != 0):
		sum+= int(temp%10)
		temp /=10
	ans = True if x % sum == 0  else False
	return ans
