def answer(l):
	l = sorted(l, reverse=True)
	n = len(l)

	ans = 0

	for bit_mask in range(1, 2**n):
		cur = 0

		for i in range(n):
			if bit_mask & 2**i:
				cur = cur*10 + l[i]

		if cur % 3 == 0:
			ans = max(ans, cur)

	return ans
