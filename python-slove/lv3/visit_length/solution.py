def is_out(cur_point):
	if (cur_point[0] > 10 or cur_point[0] < 0 or cur_point[1] > 10 or cur_point[1] < 0):
		return True
	else:
		return False

def move(map, cur_point, command):
	dc = [0, 0, 1, -1]
	dr = [-1, 1, 0, 0]
	if command == "U":
		cur_point[0] += dr[0]
		cur_point[1] += dc[0]
	if command == "D":
		cur_point[0] += dr[1]
		cur_point[1] += dc[1]
	if command == "R":
		cur_point[0] += dr[2]
		cur_point[1] += dc[2]
	if command == "L":
		cur_point[0] += dr[3]
		cur_point[1] += dc[3]
	return cur_point

def back_move(map, cur_point, command):
	dc = [0, 0, 1, -1]
	dr = [-1, 1, 0, 0]
	if command == "U":
		cur_point[0] -= dr[0]
		cur_point[1] -= dc[0]
	if command == "D":
		cur_point[0] -= dr[1]
		cur_point[1] -=dc[1]
	if command == "R":
		cur_point[0] - dr[2]
		cur_point[1] - dc[2]
	if command == "L":
		cur_point[0] -= dr[3]
		cur_point[1] -= dc[3]
	return cur_point

def solution(dirs):
	map = [[0 for col in range(0, 11)] for row in range(0, 11)]
	dc = [0, 0, 1, -1]
	dr = [-1, 1, 0, 0]
	map[5][5] = 1
	cur_point = [5, 5]

	for command in dirs:
		cur_point = move(map, cur_point, command)
		if is_out(cur_point):
			back_move(map, cur_point, command)
		map[cur_point[0]][cur_point[1]] = 1




	for row in map:
		print(row)

	return 0
