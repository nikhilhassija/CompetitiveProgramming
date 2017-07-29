from fractions import gcd

def binpow(a, b, m):
	r = 1

	while b:
		if b % 2:
			r = (r * a) % m

		b = b // 2
		a = (a * a) % m

	return r

mod1 = (10 ** 9) + 7
mod2 = (10 ** 9) + 9

t = int(input())

for _ in range(t):
	n = int(input()) - 1

	p = (n + 1) * (n)
	q = 2 * (2 * n - 1)

	g = gcd(p, q)

	p, q = p // g, q // g

	ans1 = (p * binpow(q, mod1 - 2, mod1)) % mod1
	ans2 = (p * binpow(q, mod2 - 2, mod2)) % mod2

	print(ans1, ans2)