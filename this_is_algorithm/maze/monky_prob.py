from collections import deque

def main():

	que = deque()
	k  = int(input())
	h, w = map(int, input().split())
	maze = []


	for _ in range(h):
		maze.append(list(map(int, input().split())))

	dh_x = [2, -2, 0, 0]
	dh_y = [0, 0, 2, -2]
	d_p = [1, -1]
	d_x = [1,-1, 0, 0]
	d_y = [0, 0, 1, -1]

	def bfs(x,y):

		que.append((x,y))
		count = 0

		while que :
			print(k ,",", count)
			if count == k:

				for dot in range(4):

					nx = x + d_x[dot]
					ny = y + d_y[dot]

					if nx >= w or ny >= h or nx < 0 or ny < 0:
						continue

					if maze[nx][ny] == 1:
						continue

					if maze[nx][ny] == 0:

						que.append((nx, ny))
						maze[nx][ny] = maze[x][y] + 1
						print(que, " : ", maze[nx][ny])

			x,  y  = que.popleft()
			if k > count:

				for j in range(4):

					mx = x + dh_x[j]
					my = y + dh_y[j]

					for p in range(len(d_p)):

						mx = mx + d_p[p]
						my = my + d_p[p]
						# print("mx: ",mx,"my: " ,my)

						if mx >= w or my >= h or mx < 0 or my < 0:
							continue

						if maze[mx][my] == 1:
							continue

						if maze[mx][my] == 0:

							que.append((mx,my))
							maze[mx][my] = maze[x][y] + 1
							count += 1
							# print(que, " : ",maze[mx][my])

		return maze[h - 1][w - 1]

	print(bfs(0,0))


if __name__ == "__main__":

	main()


