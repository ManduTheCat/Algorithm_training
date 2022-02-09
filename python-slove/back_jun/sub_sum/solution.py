# 1806, 부분합
import sys

N, S = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

start, end, sum = 0, 0, 0
min_ = 100001

while True:
	# sum이 s 이상이 되면 start를 하나 증가시킴
	if sum >= S:
		sum -= arr[start]   # start의 위치 1 증가
		start += 1
		min_ = min(min_, end - start + 1)   # start~end까지가 현재 최소값보다 작으면 최소값 갱신
	else:
		if end == N:    # end=N되면 탐색 종료
			break
		else:
			sum += arr[end]     # end 위치 1 증가
			end += 1

if min_ == 100001:  # 초기 min값과 같다면 sum이 S를 넘지 못한 것
	min_ = 0
print(min_)
