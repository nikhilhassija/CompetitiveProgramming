n, m = map(int, input().split())

if m == n-1:
	print("01" * (n-1), end="")
	print(0)

elif m == n:
	print("01" * m)

elif m > n and m <= 2 * (n + 1):
	print("110" * (m - n), end="")

	if m == (2 * n) + 1:
		print(1, end="")
	elif m == (2 * n) + 2:
		print(11, end="")
	else:
		print("10" * (2 * n - m), end="")

	print("")
else:
	print(-1)