from math import exp 
import decimal

def solve(a, n):
	decimal.getcontext().prec = 400

	ans = 0

	mul = 1

	two = decimal.Decimal(2)

	while(n):
		# print("{} {}".format(a, n))

		if a >= 2:
			b = int(a) - 1

			ans += mul * b * int((n * (n+1)) / two)
			a = a - b
		elif a > 1:
			b = (a/(a-1))
			m = int((a-1) * n)
			x = int(a * n)

			ans += mul * int((x * (x + 1)) / two)
			a, n = b, m

			mul *= -1
		else:
			assert(0)

	return ans

e = decimal.Decimal("2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642742746639193200305992181741359662904357290033429526059563073813232862794349076323382988075319525101901157383418793070215408914993488416750924476146066808226480016847741185374234544243710753907774499206955170276183860626133138458300075204493382656029760673711320070932870912744374704723069697720931014169283681902551")

n = int(input())


if(n > 10**100):
	exit(1)

n = decimal.Decimal(n)

a = solve(e, n)
print(a)
