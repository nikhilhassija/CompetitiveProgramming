import math

def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return int(i)
    return 0

def baseN(num,b,numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
    return ((num == 0) and numerals[0]) or (baseN(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b])

c = 0
a = input()
print("Case #1:")
p = input().split()
p[0] = int(p[0])
p[1] = int(p[1])

for i in range(2**(p[0]-2),2**(p[0]-1)):
	if(c == p[1]):
		break

	s = str(baseN(i,2)) + "1"

	flag = 1
	a = []

	for x in range(2,11):
		n = int(s,x)
		# print(is_prime(n))
		if(is_prime(n)):
			a.append(is_prime(n))
		else:
			flag = 0
			break

	if(flag):
		c += 1
		print(s,end=" ")
		for x in a:
			print(x,end=" ")
		print("")
