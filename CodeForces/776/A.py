s = input().split()

n = int(input())

print(*s)

for _ in range(n):
	a = input().split()

	s.remove(a[0])
	s.append(a[1])

	print(*s)
	