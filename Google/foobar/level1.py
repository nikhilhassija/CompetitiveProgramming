def gen_primes():
	max_n = 10**6

	is_prime = [1 for i in range(max_n)]

	P = ""

	for p in range(2, max_n):
		if is_prime[p]:
			for mul in range(2*p, max_n, p):
				is_prime[mul] = 0
			P = P + str(p)

			if len(P) > 10005:
				return P

	return P

def answer(n):
	P = gen_primes()
	return P[n:n+5]

print(answer(3))