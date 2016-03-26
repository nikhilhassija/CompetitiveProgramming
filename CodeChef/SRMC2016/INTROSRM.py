t = int(input())

for x in range(t):
	a = input()
	a = a[::-1]
	p = 0
	for i in range(len(a)):
		if(a[i] != '0'):
			p = i
			break
	print(a[p:])