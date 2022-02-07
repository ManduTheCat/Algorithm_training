def solution(answers):
	p1 = [1, 2, 3, 4, 5]
	p2 = [2, 1, 2, 3, 2, 4, 2, 5] #8
	p3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
	patton =  [p1, p2, p2]
	patton_count = list()
	ans = list()
	# 패턴을 동시에 볼 수 도 있다 여기서 틀린거 같은데..
	# answers 길이만큼만 돌아야한다
	for pt in patton:
		ans_count =  0
		for i in range(len(answers)):
			if answers[i] == pt[i % len(pt)]:
				ans_count += 1
		patton_count.append(ans_count)
	max_count = max(patton_count)

	ans = list()
	for person, score in enumerate(patton_count):
		if score == max_count and score != 0:
			ans.append(person + 1)

	return ans
