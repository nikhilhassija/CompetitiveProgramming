t = int(input())

for _t in range(t):
	n = int(input())
	A = sorted(list(map(int, input().split())))

	L = A[:n]
	R = A[n:]

	A = zip(L, R)

	print(R[n//2])

	for i,j in A:
		print("{} {} ".format(i, j), end="")

	print()