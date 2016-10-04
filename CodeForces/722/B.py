n = int(input())

V = {'a','e','i','o','u','y'}

p = input().split()
p = [int(i) for i in p]

c = [0 for i in range(n)]

for i in range(n):
	A = list(input())
	for v in V:
		c[i] += A.count(v)

assert(len(c) == n)

flag = 1
for i in range(n):
	if(c[i] != p[i]):
		flag = 0;
		break

if(flag):
	print("YES")
else:
	print("NO")