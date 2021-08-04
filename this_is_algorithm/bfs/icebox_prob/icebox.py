def bfs(icebox, x, y, n, m):
	if x <= -1 or x >= n or y <= -1 or y > m:
		return False
	if icebox[x][y] == 0:
		icebox = 1
		bfs(x - 1, y)
		bfs(x + 1, y)
		bfs(x, y - 1)
		bfs(x, y + 1)
		
		return True

def main():
	n, m = map(int, input().split())
	icebox = []
	result = 0

	for i in range(n):
		icebox.append(list(map(int, input().split())))
	print(icebox)

if __name__ == "__main__":
	main()