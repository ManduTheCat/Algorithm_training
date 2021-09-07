n = int(input())

member = []

for _ in range(n):
	member.append(list(input().split()))

print(member)

member.sort(key = lambda a : int(a[1]))

print(member)
