
def edit(lis, time):
	if time == 0:
		return 0
	time -= 1
	lis.append(1)
	edit(lis, time)

def main():
	lis1 = [1,2,3]
	edit(lis1, 3)
	print(lis1)

if __name__ == "__main__":
    main()
