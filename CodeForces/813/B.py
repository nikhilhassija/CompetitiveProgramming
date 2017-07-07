#!/usr/bin/python3 

x, y, l, r = map(int, input().split())

A = []
B = []

a = 1

while a < r:
	A.append(a)
	a *= x

b = 1

while b < r:
	B.append(b)
	b *= y

X = [l-1, r+1]

for a in A:
	for b in B:
		s = a + b
		if(l <= s and s <= r):
			X.append(s)

X = sorted(X)

ans = 0

for i in range(len(X)-1):
	ans = max(ans, X[i+1] - X[i] - 1)

print(ans)  