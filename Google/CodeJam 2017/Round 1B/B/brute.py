T = int(input())

for t in range(1, T+1):
	N, R, O, Y, G, B, V = map(int, input().split())

	if R > N/2 or B > N/2 or Y > N/2:
		print("Case #{}: IMPOSSIBLE")
	else:
		X = min(R, Y, B)
		