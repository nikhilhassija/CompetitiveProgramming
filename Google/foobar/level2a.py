def answer(l, t):
	n = len(l)

	ans_b = False
	ans_t = [-1, -1]

	for i in range(n):
		for j in range(i, n):
			cur = l[i:(j+1)]
			cur_t = [i, j]

			if sum(cur) == t:
				if not ans_b:
					ans_b = True
					ans_t = cur_t

				ans_t = min(ans_t, cur_t) 

	return ans_t