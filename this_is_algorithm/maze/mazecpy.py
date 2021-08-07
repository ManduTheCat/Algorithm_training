from collections import deque

def main():

	n, m = map(int, input().split())
	maze = []
	for _ in range(n):
		maze.append(list(map(int, input().split())))

	dx = [0, 0, 1, -1]
	dy = [1, -1, 0, 0]

	x = 0
	y = 0

	que = deque()

	def bfs(x, y):

		que.append((x,y))

		while que:
			x, y  = que.popleft()

			for i in range(4):

				nx = dx[i] + x
				ny = dy[i] + y

				if nx >= n or ny >= m or nx < 0 or ny < 0:
					continue

				if maze[x][y] == 0:
					continue

				if maze[nx][ny] == 1:
					que.append((nx,ny))
					maze[nx][ny] = maze[x][y] + 1

		return maze[n - 1][m - 1]

	print(bfs(0,0))


if __name__ == "__main__":
	main()
