import sys


def main():
	n = int(sys.stdin.readline().rstrip())
	m = int(sys.stdin.readline().rstrip())
	arr_m = [0 for i in range(11)]
	arr_n = list()
	flag = 1

	if m > 0:
		temp = list(map(int,sys.stdin.readline().split()))
		for num in temp:
			arr_m[num] = 1

	if n == 100:
		print(0)
		return 0

	if m == 10 or m == 0 :
		if n > 100:
			print(n - 100)
			return 0
		else:
			print(100 - n)
			return 0

	temp_up = n
	while(flag): # + 방향으로 이둥 해서 가장 가까운 숫자찾기
		arr_n = list(map(int, str(temp_up)))
		for i in arr_n:
			if arr_m[i] == 1:
				temp_up +=1
				flag = 1
				break
			else:
				flag = 0
	print(temp_up, "-" , n ,"=", temp_up - n) # 출력 확인용
	temp_down = n
	flag = 1

	while(flag): # - 방향으로 이동 해서 가장 가까운 숫자 찾기
		if temp_down < 0:
			temp_down = -1
			break
		arr_n = list(map(int, str(temp_down)))
		for i in arr_n:
			if arr_m[i] == 1:
				temp_down -=1
				flag = 1
				if n - temp_down > temp_up - n: # 중간에 + 방향이동한 숫자보다 멀어지면 중단
					flag = 0
				break
			else:
				flag = 0
	print(n, "-", temp_down, "=", n - temp_down) # 출력 확인용

	if(temp_down == -1):
		min_shift = temp_up - n
	else:
		min_shift = min(temp_up -n, n - temp_down)

	if len(list(map(int, str(temp_down)))) > len(list(map(int, str(temp_up)))):
		near_num = temp_up
	else:
		near_num = temp_down

	res = min_shift + len(list(map(int, str(near_num))))
	print(res)

if __name__ == "__main__":
	main()
