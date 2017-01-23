def power(spell, health):
	# print("Spell: {}".format(spell))

	if '+' in spell:
		spell, h = map(str, spell.split('+'))
		health -= int(h)
	if '-' in spell:
		spell, h = map(str, spell.split('-'))
		health += int(h)

	x, y = map(int, spell.split('d'))

	prob_dist = [[0 for i in range((x+2)*y)] for j in range(x)]

	for i in range(y):
		prob_dist[0][i+1] = 1

	# print(prob_dist[0])

	# print("X: {} \t Y: {}".format(x, y))

	for i in range(1, x):
		for s in range(1, y+1):
			for j in range(x*y + 1):
				prob_dist[i][j + s] += prob_dist[i-1][j]

	hsum = 0
	tsum = 0

	# print("Health: {}".format(health))
	# print(prob_dist[x-1])

	for i in range(len(prob_dist[x-1])):
		if i >= health:
			hsum += prob_dist[x-1][i]
		tsum += prob_dist[x-1][i]

	return float(hsum) / float(tsum)

tests = int(input())

for t in range(tests):
	inp = input()
	h, s = map(int, inp.split())

	ans = 0

	spells = input().split()

	for spell in spells:
		if not ('-' in spell or '+' in spell):
			spell = spell + '+0'

		p = power(spell, h)

		ans = max(ans, p)

	print("Case #{}: {:.10f}".format(t+1, ans))
