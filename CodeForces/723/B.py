n = int(input())

A = input().strip()

A = A.strip('_')

A = A.replace('()','_')

while "__" in A:
	A = A.replace("__","_")

A = A.split('(')
P = []
NP = []

while '' in A:
	A.remove('')

for i in range(len(A)):
	if ')' in A[i]:
		NP.append(A[i].split(')')[1])
		P.append(A[i].split(')')[0])
	else:
		NP.append(A[i])

while '' in NP:
	NP.remove('')
while '' in P:
	P.remove('')


NPS = []
for i in NP:
	NPS.extend(i.strip('_').split('_'))

ans1 = 0
for i in NPS:
	ans1 = max(ans1, len(i))

PS = []
for i in P:
	PS.extend((i.strip('_')).split('_'))

while '' in PS:
	PS.remove('')

ans2 = len(PS)

print("{} {}".format(ans1,ans2))