import solution
import dfs_solution
def main():
	input1 = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
	input2 = [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
	print(solution.solution(3, input1))
	print(solution.solution(3, input2))

def dfs_main():
	input1 = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
	input2 = [[1, 1, 0], [1, 1, 1], [0, 1, 1]]
	print(dfs_solution.solution(3, input1))
	print(dfs_solution.solution(3, input2))

if __name__ == "__main__":
	dfs_main()
