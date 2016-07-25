a = "abcdefghijklmnopqrstuvwxyz"
a = list(a)

S = str(input())

ans = 0

for i in range(len(a)):
	for j in range(len(a)):
		s = "{}{}{}{}".format(a[i],a[j],a[j],a[i])
		print("{}-{}".format(s,S.count(s)))
		ans += S.count(s)

print(ans)