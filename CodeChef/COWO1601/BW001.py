q = int(input())

d = {}

for i in range(q):
	c = input().split()
	if(c[0] == "1"):
		d[c[1]] = "yes"
	else:
		print(d.get(c[1],"no"))