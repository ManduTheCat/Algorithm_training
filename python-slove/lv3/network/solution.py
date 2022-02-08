from collections import deque

def solution(n, computers):
	ans = 0
	check = [False for i in range(1, n + 1)]
	for i in range(len(computers)):
		if check[i] == False:
			dfs(i, computers, check)
			ans +=1
	return ans

def dfs(node, computers, check):
	q = deque()
	check[node] = True
	q.appendleft(node)
	while not len(q) == 0:
		cur_node = q[-1]
		q.pop()
		for i in range(len(computers[cur_node])):
			if check[i] == False and computers[cur_node][i] == 1 and cur_node != i:
				check[i] = True
				q.appendleft(i)
