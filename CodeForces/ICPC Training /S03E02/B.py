from decimal import *
from math import log

a = input().split()

n = int(a[0])
k = int(a[1])

getcontext().prec = k + 5

s = Decimal(n).sqrt()
s = str(s)

if('.' not in s):
	s = s + '.0'

s = s.split('.')

a = s[0]

b = s[1]
b = b + "0"*k
b = list(b)
b = b[:k]
b = ''.join(b)

print("{}.{}".format(a,b))