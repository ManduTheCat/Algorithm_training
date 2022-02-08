
def solution(s):
	s = list(s)
	# 스텍 뺴면서 다른거 만나면  + 1
	# 같은거 만나면 넘어가기?
	#  처음 앞 ) 맨뒤 ( 거르기
	if s[-1] == "(" or s[0] == ")":
		return False
	count = 0
	for bracket in s:
		if	bracket == "(":
			count +=1
		elif bracket == ")" and count > 0:
			count -=1
		else :
			return False

	return count == 0
