tests = int(input())

for t in range(tests):
	n = int(input())

	A = []
	for _ in range(n):
		s = input()
		A.append((-len(set(list(s.replace(' ', '')))), s))

	A = sorted(A)

	print("Case #{}: {}".format(t+1, A[0][1]))