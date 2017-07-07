t = int(input())

for _ in range(t):
	n = input()

	ans = 0

	if(n[0] == '-'):
		ans -= 2 * int(n)
		ans += 10 ** (len(n) - 2)
	else:
		ans += 10 ** (len(n) - 1)

exit(0)