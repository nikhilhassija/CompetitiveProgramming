a, b, l, r = map(int, input().split())

A = [chr(ord("a") + i) for i in range(26)]

s = ''.join(A[:a])

turn = 0

for i in range(1000):
	if turn % 2:
		x = list(s[-a:])

		L = list(A)
		for _x in x:
			if _x in L:
				L.remove(_x)

		for j in range(a):
			s += L[j] 
	else:
		s += s[-1] * b

	turn += 1

g = s[-a:]

for i in range(8):
	if turn % 2:
		x = list(g[-a:])

		L = list(A)
		for _x in x:
			if _x in L:
				L.remove(_x)

		for j in range(a):
			g += L[j] 

	else:
		g += g[-1] * b

	turn += 1 

g = g[a:]

S = set([])

if l < 1000:
	S = set(list(s[l-1:min(1000, r)]))

l = max(l, 1000)


if l <= r:
	gen_turns = (r - l) // (a + b)

	if not gen_turns > 4:
		g = g[(l-1) % ((a + b) * 2):(l % ((a + b) * 2)) + ((r - l) % ((a + b) * 2))]

	S.update(list(g))

print(len(S))