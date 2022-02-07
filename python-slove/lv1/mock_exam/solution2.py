def solution(answers):
	ans = []
	p1 = [1,2,3,4,5]
	p2 = [2,1,2,3,2,4,2,5]
	p3 = [3,3,1,1,2,2,4,4,5,5]

	count1, count2, count3 = 0, 0, 0
	for i in range(len(answers)):
		if answers[i] == p1[i % len(p1)]:
			count1+=1
		if answers[i] == p2[i % len(p2)]:
			count2+=1
		if answers[i] == p3[i % len(p3)]:
			count3+=1
	answer_temp = [count1, count2, count3]

	for person, score in enumerate(answer_temp):
		if score == max(answer_temp):
			ans.append(person+1)
	return ans
