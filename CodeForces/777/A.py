a = [0, 1, 2]

print("{} {}".format(0, a))

for i in range(100):
	if(i % 2):
		a[0], a[1] = a[1], a[0]
	else:
		a[1], a[2] = a[2], a[1]

	print("{} {}".format(i+1, a))	