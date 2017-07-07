T = int(input())

for t in range(T):
	n, q = map(int, input().split())

	S = []
	for i in range(n):
		S.append(input())

	X = input()

	for i in range(n):
		S[i] = list(map(int, S[i].replace("T", "1").replace("F", "0")))

	X = list(map(int, X.replace("T", "1").replace("F", "0")))

	A = list(map(int, input().split()))

	score = 0

	for x in range(2 ** q):
		f = "{:0" + str(q) + "b}"
		k = f.format(x)
		K = list(map(int, list(k)))

		flag = True
		for i in range(n):
			s = 0
			for a, b in zip(S[i], K):
				s += 1 ^ a ^ b

			if(s != A[i]):
				flag = False

		if(flag):
			s = 0
			for a, b in zip(X, K):
				s += 1 ^ a ^ b

			score = max(score, s)

	print("Case #{}: {}".format(t+1, score))