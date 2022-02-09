def solution(n, computers):
	path_check = [False for i in range(0, n + 1) ]
	count = 0
	for i in range(len(computers)):
		if path_check[i] == False:
			dfs(i, path_check, computers)
			count +=1
	return count

def dfs(node, path_check, computers):
	path_check[node] = True
	for next_node in range(len(computers[node])):
		if path_check[next_node] == False and next_node != node and computers[node][next_node] ==1:
			dfs(next_node, path_check, computers)

