k = 2 * int(input())

A = [0 for i in range(10)]

for i in range(4):
	s = input().replace(".", "")

	s = map(int, list(s))

	for t in s:
		A[t] += 1

if max(A) <= k:
	print("YES")
else:
	print("NO")