
def main():


	numOfcoin, n = map(int, input().split())
	coin_type = list(range(0, numOfcoin))
	count = 0;

	for i in range(0, numOfcoin ):
		coin_type[i] = int(input())


	for coin in reversed(coin_type):
		count += n // coin
		n = n % coin
	print(count)

if __name__ == '__main__':

	main()
