from collections import deque

def bfs(graph, start, visted):
	
	que = deque([start])
	visted[start] = True

	while que:
		v = que.popleft()
		print(v, end =' ')
		
		for i in graph[v]:
			
			if not visted[i]:
				que.append(i)
				visted[i] = True

def main():
	graph = [[], [2,3,8], [1,7], [1,4,5], [3,5], [3,4], [7], [8,2,6], [1,7]]
	visited = [False] * 9

	bfs(graph, 1, visited)

if __name__ == "__main__":
	main()