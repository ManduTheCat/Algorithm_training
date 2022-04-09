import sys
from collections import deque

def main():
	count_pc  = int(sys.stdin.readline())
	vertex_count = int(sys.stdin.readline())
	visit_check = [False for i in range(count_pc + 1)]
	network = []
	adj_list= [[] for _ in range(count_pc + 1)]
	for i in range(vertex_count):
		vertex = list(map(int,(sys.stdin.readline().split())))
		network.append(vertex)
	# dfs? bfs? 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
	# 양방향 리스트
	for edge in network:
		adj_list[edge[0]].append(edge[1])
		adj_list[edge[1]].append(edge[0])

	#bfs
	q = deque()
	count = 0
	for num in adj_list[1]:
		q.append(num)

	while(len(q) != 0):
		cur_node = q.pop()
		for next_node in adj_list[cur_node]:
			if visit_check[next_node] == False:
				count+=1
				visit_check[next_node] = True
				q.append(next_node)


	print(count -1)
if __name__ == "__main__":
	main()
