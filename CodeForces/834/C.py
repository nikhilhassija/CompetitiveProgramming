def cuberoot(x):
	return int(x ** (1. / 3))

def check(x, y, c):
	p = x * y

	if not c:
		return 0

	if p != c ** 3:
		return 0

	if x % c or y % c:
		return 0

	return 1

n = int(input())

for _ in range(n):
	x, y = map(int, input().split())

	c = cuberoot(x * y)

	if check(x, y, c - 1) or check(x, y, c) or check(x, y, c + 1):
		print("Yes")
	else:
		print("No")