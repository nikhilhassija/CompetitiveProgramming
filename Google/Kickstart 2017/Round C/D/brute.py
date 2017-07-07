def check(l, mean, median, r, n):
	tot = mean * n;
	A = [l for i in range(n)]
	A[n-1] = r

	tot -= l * (n-1)
	tot -= r

	if tot < 0:
		return 0

	for i in range(n//2, n-1):
		A[i] = median
		tot += median - l

	if tot < 0:
		return 0

	k = n // 2 - 1;
	while tot > 0 and k > 0:
		x = min(tot, median - l)

		A[k] += x
		tot -= x

		k -= 1

	if tot == 0:
		# print(A)
		return 1

	k = n // 2 + 1 + (1 ^ (n % 2))
	while tot > 0 and k < n:
		x = min(tot, r - median)

		A[k] += x
		tot -= x;

		k += 1

	if tot == 0:
		return 1

	return 0


T = int(input())

for t in range(T):
	MIN, MAX, MEAN, MEDIAN = map(int, input().split())

	if MIN > MAX or MEAN < MIN or MEAN > MAX or MEDIAN < MIN or MEDIAN > MAX:
		print("Case #{}: IMPOSSIBLE".format(t+1))
	else:
		l = 1

		if MEDIAN != MIN and MEDIAN != MAX:
			l = 3

		h = int(1e5)

		ans = int(1e9)

		while l <= h:
			m = (l + h) // 2


			b = check(MIN, MEAN, MEDIAN, MAX, int(m)) 

			# print("{} -- {}".format(m, b))

			if b:
				ans = min(ans, int(m))
				h = m - 1
			else:
				l = m + 1

		if ans == int(1e9):
			print("Case #{}: IMPOSSIBLE".format(t+1))
		else:
			print("Case #{}: {}".format(t+1, ans))
