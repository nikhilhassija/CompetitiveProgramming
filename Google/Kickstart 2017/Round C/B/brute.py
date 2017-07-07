import itertools

t = int(input())

for _t in range(t):
	f = False

	n = int(input())

	A = []
	for _ in range(n):
		A.append(input())

	X = []
	for i in range(n//2 + 1):
		s = ("." * min(i, n - i)) + "X" + ("." * (n//2 - min(i, n-i)))
		s = s[:len(s) - 1] + s[::-1]
		X.append(list(s))

	X.extend(X[:-1][::-1])

	P = [i for i in range(n)]

	for p in itertools.permutations(P):
		Q = [i for i in range(n)]
		for q in itertools.permutations(Q):
			B = [[] for i in range(n)]

			k = 0
			for i in p:
				for j in q:
					B[k].append(A[i][j])

				k += 1

			f = f or (B == X)

	if f:
		print("Case #{}: POSSIBLE".format(_t+1))
	else:
		print("Case #{}: IMPOSSIBLE".format(_t+1))