t = int(input())

for _ in range(t):
	A = input()
	
	if(A == ''.join(sorted(A))):
		print("yes")
	else:
		print("no")