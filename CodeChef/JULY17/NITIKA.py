t = int(input())

for _ in range(t):
	A = input().split()

	for i in range(len(A) - 1):
		print("{}.".format(A[i][0].upper()), end=" ")

	print(A[-1].capitalize())