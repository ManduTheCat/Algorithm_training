def main():
	n, m, k  = map(int, input().split())
	data = list(map(int, input().split()))

	data.sort()
	first = data[n - 1]
	second = data[n -2]

	count = int(m / (k + 1)) * k #가장 큰수가 더해지는 횟수 = 수열 반복횟수 * 중복횟수
	count += m % (k + 1) #나누어 떨어지지 않는다면 나머지 만큼 더해준다

	result = 0
	result += (count) * first
	result += (m - count) * second

	print(result)


if __name__ == "__main__":
	main()

