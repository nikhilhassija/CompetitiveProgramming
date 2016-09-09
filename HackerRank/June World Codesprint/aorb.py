def HEX(A):
	A = ''.join(list(map(str,A)))
	A = int(A,2)
	A = hex(A).replace("0x","")
	return A

q = int(input())

for qq in range(q):
	k = int(input())
	a = int(input(),16)
	b = int(input(),16)
	c = int(input(),16)
	A = list(bin(a).replace('0b',''))
	B = list(bin(b).replace('0b',''))
	C = list(bin(c).replace('0b',''))

	m = max(len(A),len(B),len(C))

	A = list("0"*(m-len(A))) + A
	B = list("0"*(m-len(B))) + B
	C = list("0"*(m-len(C))) + C

	for i in range(m):
		A[i] = int(A[i])
		B[i] = int(B[i])
		C[i] = int(C[i])

	for i in range(m):
		s = "{}{}{}".format(A[i],B[i],C[i])
		if s == "000":
			continue
		if s == "001":
			B[i] = 1
			k -= 1
		if s == "010":
			B[i] = 0
			k -= 1 
		if s == "011":
			continue
		if s == "100":
			A[i] = 0
			k -= 1
		if s == "101":
			continue
		if s == "110":
			A[i] = 0
			B[i] = 0
			k -= 2
		if s == "111":
			continue

	if k < 0:
		print("-1")
	if k == 0:
		print(HEX(A).upper())
		print(HEX(B).upper())
	if k > 0:
		for i in range(m):
			s = "{}{}{}".format(A[i],B[i],C[i])
			if s == "000":
				continue
			if s == "011":
				continue
			if s == "101":
				if k > 1:
					A[i] = 0
					B[i] = 1
					k -= 2
			if s == "111":
				if k > 0:
					A[i] = 0
					k -= 1
					
		print(HEX(A).upper())
		print(HEX(B).upper())