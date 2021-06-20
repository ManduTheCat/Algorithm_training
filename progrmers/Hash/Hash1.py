def solution(participant, completion):
	answer = ' '
	temp = 0
	dic = {}
	for part in participant:
		dic[hash(part)] = part
		temp += int(hash(part))
	for com in completion:
		temp -= hash(com)
	answer = dic[temp]
	return answer




def main():
	complietion = ["eden", "kiki"]
	participant = ["leo", "kiki", "eden"]
	print(solution(participant,complietion))
	#return "reo"
if __name__ == '__main__':
	main()
