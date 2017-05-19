A = list(input())
B = list(input())

A = sorted(A)
B = sorted(B)[::-1]

n = len(A)

for i in range(n):
	if i % 2:
		print(B[i//2], end="")
	else:
		print(A[i//2], end="")

print("")