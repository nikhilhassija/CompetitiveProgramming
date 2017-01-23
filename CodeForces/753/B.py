a = []

for i in range(10):
	s = str(i)*4

	print(s)
	x = input().split()
	x = [int(i) for i in x]
	if x.count(0) != 2:
		a.append(str(i))

import itertools
p = list(itertools.permutations(a))

for i in p:
	print(''.join(i))

	x = input()
	if x == "4 0":
		break