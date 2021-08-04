from collections import deque

def bfs(graph, start, flag):
	que = deque()



def main():
	n, m = map(int, input().split())
	icebox = []
	flag = [False] * (n * m)

	for i in range(n):
		icebox.append(list(map(int, input().split())))
	print(icebox)

if __name__ == "__main__":
	main()