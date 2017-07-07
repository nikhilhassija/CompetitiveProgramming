from decimal import *

def de(d):
	m = 10**(d+3)
	e = m
	f = 1
	k = 1
	while(1):
		f *= ((3*k-2)*(3*k-1)*(3*k))
		if(f > m): break;
		e += (((9*k*k)+1)*m)//f
		k += 1

	return e//(1000)

def es(a, n):
	getcontext().prec = 2*(len(str(n))) + 10
	getcontext().rounding = ROUND_DOWN
	r, m, o, t, z = Decimal(0), Decimal(1), Decimal(1), Decimal(2), Decimal(0)
	f = Decimal(1)

	# for i in range(8000):
	while(n):
		if a >= t:
			b = (a).to_integral_exact() - o
			r += (m * b * n * (n+o)).to_integral_exact()
			a -= b
		elif a > o:
			y = a - o
			b = a

			
			x = (a*n).to_integral_exact()

			r = (r*y).to_integral_exact()
			r += (f * m * x * (x+o)).to_integral_exact()

			f = (f*y)

			a, n = b, x - n
			m *= -o

	print(r)
	print(f)
	print(t)

	return ((r) // (f * t).to_integral_exact())

n = input()
e = str(de(2*len(str(n)) + 10))
e = e[0] + '.' + e[1:]
s = es(Decimal(e), Decimal(n))
print(s)