def dfs(graph, v, visted):
	
	visted[v] = True
	print(v, end = '\n')
	
	for i in graph[v]:
		
		if not visted[i]:
			
			dfs(graph, i, visted)


def main():
	graph = [[], [2,3,8], [1,7], [1,4,5], [3,5], [3,4], [7], [8,2,6], [1,7]]
	visited = [False] * 9
	print(graph[1])

	# dfs(graph, 1, visited)

if __name__ == "__main__":
	main()