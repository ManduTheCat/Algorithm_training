def solution(n):
	count_bin = bin(n).count('1')
	for num in range(n + 1, 1000000):
		if bin(num).count('1') == count_bin:
			return num
	return answer
