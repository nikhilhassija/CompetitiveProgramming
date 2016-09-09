tests = int(input())

for t in range(tests):
	a = input()
	b = input()

	a = str.upper(a)

	i = 0
	j = 0 

	while i < len(a) and j < len(b):
		if(a[i] == b[j]):
			j += 1

		i += 1

	if j == len(b):
		print("YES")
	else:
		print("NO")