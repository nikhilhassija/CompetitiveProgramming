def color(x):
	if x < 400:
		return "grey"
	
	if x < 800:
		return "brown"

	if x < 1200:
		return "green"

	if x < 1600:
		return "cyan"

	if x < 2000:
		return "blue"

	if x < 2400:
		return "yellow"

	if x < 2800:
		return "orange"

	if x < 3200:
		return "red"

	return "x"

colors = ["grey", "brown", "green", "cyan", "blue", "yellow", "orange", "red"]
C = []

n = int(input())

c = 0

A = list(map(int, input().split()))

for a in A:
	if(color(a) == "x"):
		c += 1
	else:
		C.append(color(a))

C = list(set(C))

m = len(C) + c

if(len(C) == 0):
	C.append("x")

print("{} {}".format(len(C), m))