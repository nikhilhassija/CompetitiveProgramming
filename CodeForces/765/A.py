n = int(input())

h = input()

d = 0

for i in range(n):
	a = input().split('->')

	if a[0] == h:
		d += 1

	if a[1] == h:
		d -= 1

if d:
	print("contest")
else:
	print("home")