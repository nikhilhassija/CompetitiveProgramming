import sys
from random import shuffle

def change(A, B):
	X = []

	for i in range(len(A)):
		if A[i] == '0':
			if B[i] == '1':
				X.append("+{}".format(i+1))
		else:
			if B[i] == '0':
				X.append("-{}".format(i+1))

	X.sort()
	print(''.join(X[::-1]), end="")

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

n, k = map(int, input().split())

if k == 1:
	ans = "+1"

	for i in range(1, n):
		ans += "++{}".format(i)

	ans += "-{}".format(n)
	
	print(ans)	

	exit(0)

X = [[] for i in range(n)]

for i in range(2 ** n):
	f = "{:0" + str(n) + "b}"
	s = f.format(i)

	if s.count("1") == k:
		X[s.index("1")].append(s)

# print(X)

print("+1", end="")

for i in range(len(X)):
	X[i].reverse()
	l = ("0" * i) + "1" + ("0" * (n-1-i))

	for x in X[i]:
		change(l, x)
		l = x

	if i != (len(X) - 1):
		if len(X[i+1]) == 0:
			break;
		else:
			print("++{}".format(i+1), end="")

print("")