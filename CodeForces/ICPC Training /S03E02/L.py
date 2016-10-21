n = int(input())

A = input().split()

R = []
B = []

for i in A:
	if 'R' in i:
		R.append(int(i.replace('R','')))
	if 'B' in i:
		B.append(int(i.replace('B','')))

R.sort()
R.reverse()

B.sort()
B.reverse()

knots = min(len(R),len(B))

sum = 0
for i in range(knots):
	sum += R[i] + B[i]

sum -= 2*knots

print(sum)