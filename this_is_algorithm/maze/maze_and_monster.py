from collections import deque

def bfs(x, y, dx, dy, n, m, maze):

	que =  deque()
	que.append((x,y))
	while que:
		x, y = que.popleft()
		for i in range(4):
			nx = x + dx[i]
			ny = y + dy[i]

			if nx  < 0 or nx >= n or ny < 0 or ny >= m:
				continue

			if maze[nx][ny] == 0:
				continue

			if maze[nx][ny] == 1:
				maze[nx][ny] = maze[x][y] + 1
				que.append((nx,ny))
				print(que)
			return maze[n -1][m -1]



def main():

	n, m = map(int, input().split())
	maze = []
	for _ in range(n):
		maze.append(list(map(int, input().split())))

	dx = [1, -1, 0, 0]
	dy = [0, 0, 1, -1]
	print(bfs(0, 0, dx, dy, n, m, maze))


if __name__ == "__main__":
	main()
