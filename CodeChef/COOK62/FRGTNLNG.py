t = int(input())
for i in range(t):
	[n,k] = input().split()
	a = input().split()
	l = []
	for x in range(int(k)):
		l.extend(input().split())
	for x in a:
		if x in l:
			print("YES",end=' ')
		else:
			print("NO",end=' ')
	print("")