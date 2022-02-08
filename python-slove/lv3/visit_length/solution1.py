# 꼭 map 이 필요 하지 않다
# 우리가 구해하는건 경로의 갯수이다
# x,y, column ,row 는 추상적인 개념이다 내가 규정한대로 움직인다.
def solution(dirs):
	# 커맨드를 dict 형으로 선언
	command = {"U": (1, 0), "D" : (-1, 0), "L" : (0, -1), "R" : (0, 1)}
	route = set()
	cur_row, cur_column = (0, 0)
	for dir_command in dirs:
		next_row = cur_row + command[dir_command][0]
		next_column = cur_column + command[dir_command][1]
		if -5 <= next_column <= 5 and -5 <= next_row <= 5:
			route.add((cur_row, cur_column, next_row, next_column))
			route.add((next_row, next_column, cur_row, cur_column))
			cur_row, cur_column = next_row, next_column
	return len(route) // 2

