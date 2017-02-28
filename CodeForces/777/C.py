n, m = map(int, input().split())

A = []

for _ in range(n):
	A.append(input().split())

for i in range(n):
	for j in range(m):
		A[i][j] = int(A[i][j])

A = list(zip(*A))

S = [[0 for i in range(n)] for j in range(m)]

for i in range(m):
	S[i][0] = 1
	for j in range(1, n):
		if(A[i][j] < A[i][j-1]):
			S[i][j] = S[i][j-1] + 1
		else:
			S[i][j] = S[i][j-1]

R = [[-1 for i in range(n+1)] for j in range(m+1)]

for i in range(m):
	for j in range(1, n):
		if(S[i][j] != S[i][j-1]):
			R[i][S[i][j-1]] = j - 1
	R[i][S[i][n-1]] = n-1

X = [i for i in range(n)]

for i in range(m):
	for j in range(n):
		X[j] = max(X[j], R[i][S[i][j]])

k = int(input())

for _ in range(k):
	l, r = map(int, input().split())

	l -= 1
	r -= 1

	if(r <= X[l]):
		print("Yes")
	else:
		print("No")