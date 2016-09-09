t = int(input())

for tst in range(t):
	s = input()
	s = s.split()
	n = int(s[0])
	k = int(s[1])
	b = int(s[2])

	mxb = (b*(b+1))//2;
	mxk = (k*(k+1))//2;

	if(n >= mxb and n <= mxk):
		A = [i+1 for i in range(b)]
		n -= mxb

		i = b-1
		while(n != 0 and i>=0):
			d = min(n,abs(A[i]-k))

			A[i] += d
			k -= 1
			n -= d
			i -= 1

		if n != 0:
			print("-1")
		else:
			s = str(A)
			s = s.replace(",","")
			s = s.replace("[","")
			s = s.replace("]","")
			print(s)
	else:
		print("-1")