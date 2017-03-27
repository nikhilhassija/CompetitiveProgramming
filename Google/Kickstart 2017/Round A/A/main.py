_t = int(input())

for t in range(1, _t+1):
	n,m = map(int, input().split())

	x = min(n, m)

	ans = (x * (x + 1) * (3 * x * x + (-4*m - 4*n + 3)*x + m*(6*n - 2) - 2*n))//12
	ans %= (1000000007)

	print("Case #{}: {}".format(t, ans))