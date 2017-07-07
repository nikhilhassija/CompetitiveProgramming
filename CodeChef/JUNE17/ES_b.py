import math

t = int(input())

e = math.exp(1)

for _ in range(t):
	n = int(input())

	ans = 0
	for i in range(1, n+1):
		ans += int(e * i)

	print(ans)