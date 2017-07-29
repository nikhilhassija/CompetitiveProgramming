from random import randint

t = 1

print(t)

for _ in range(t):
	n = 9 * (10**4)

	print(n)

	for i in range(1, n):
		print(i, i+1, randint(1, 10**9))

	print(n)

	for i in range(n):
		print(randint(1, n), randint(1, n), randint(1, 10**9))