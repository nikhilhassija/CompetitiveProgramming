N = 1000000;
lp = [0 for i in range(N+1)]
pr = []

for i in range(2,N+1):
	if(lp[i] == 0):
		lp[i] = i
		pr.append(i)

	j = 0
	while j<len(pr) and pr[j]<=lp[i] and i*pr[j]<=N:
		lp[i*pr[j]] = pr[j]
		j += 1;

t = int(input())

for tt in range(t):
	n = int(input())
	A = input().split()
	for i in range(n):
		A[i] = int(A[i])

	for p in pr:
		c = 0
		for j in A:
			x = j
			while x%p == 0 and c<=2:
				x /= p
				c += 1

		if(c >= 2):
			print(p)
			break