t = int(input())

for _ in range(t):
	n = int(input())
	A = map(int, input().split())

	print(n - max(A))