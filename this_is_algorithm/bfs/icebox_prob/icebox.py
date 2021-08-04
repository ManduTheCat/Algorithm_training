def bfs(icebox, x, y, n, m):
	
	if x <= -1 or x >= n or y <= -1 or y >= m:
		return False
	
	if icebox[x][y] == 0:
		
		icebox[x][y] = 1
		bfs(icebox, x - 1, y, n, m)
		bfs(icebox, x + 1, y, n, m)
		bfs(icebox, x, y - 1, n ,m)
		bfs(icebox, x, y + 1, n ,m)
		
		return True
	
	return False

def main():
	n, m = map(int, input().split())
	icebox = []
	result = 0

	for i in range(n):

		icebox.append(list(map(int, input().split())))

	for i in range(n):
		for j in range(m):
			if bfs(icebox, i, j, n, m) == True:
				result += 1
	
	print(result)

if __name__ == "__main__":
	main()