import sys

def check(arr_m, arr_target):
	if str(type(arr_target)) == "<class 'int'>":
		arr_target = list(map(int, str(arr_target)))

	for i in arr_target:
		if	arr_m[i] == 1:
			return True
	return False



def main():
	n = int(sys.stdin.readline().rstrip())
	m = int(sys.stdin.readline().rstrip())
	arr_m = [0 for i in range(11)]
	flag = True

	if m > 0:
		temp = list(map(int,sys.stdin.readline().split()))
		for num in temp:
			arr_m[num] = 1

	if n == 100:
		print(0)
		return 0

	if m == 10 :
		print(abs(100 -n))
		return 0

	if m == 0:
		if abs(100 - n) < len(list(map(int, str(n)))):
			print(abs(100 - n))
		else:
			print(len(list(map(int, str(n)))))
		return 0

	temp_up = n
	temp_down = n

	while(flag == True):
		if temp_down < 0:
			temp_down = 0
		temp_up_list = list(map(int, str(temp_up)))
		temp_down_list = list(map(int, str(temp_down)))
		if check(arr_m, temp_down_list) and check(arr_m, temp_up_list):
			temp_up +=1
			temp_down -=1
		else:
			break

	# print(temp_up, "-" , n ,"=", temp_up - n) # 출력 확인용
	# print(n, "-", temp_down, "=", n - temp_down) # 출력 확인용

	if(temp_down == -1 or temp_down == 0):
		min_shift = temp_up - n
	else:
		min_shift = min(temp_up -n, n - temp_down)

	if not(check(arr_m , temp_down)):
		near_num = temp_down
	elif not(check(arr_m , temp_up)):
		near_num = temp_up




	res = min_shift + len(list(map(int, str(near_num))))
	if res > abs(100 - n):
		res = abs(100 -n)

	# print(len(list(map(int, str(near_num)))) ,"+", min_shift)
	# print("near_num : ",near_num)
	print(res)

if __name__ == "__main__":
	main()
