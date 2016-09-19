import random

a = input()
a = a.split()
a = [int(i) for i in a]
n = a[0]
p = a[1]

s = [i+1 for i in range(n-1)]
r = s

random.shuffle(s)
s = s[:p-1]
s.sort()
s = str(s).replace(',','').replace('[','').replace(']','')
print(s)

random.shuffle(r)
r = r[:p-1]
r.sort()
r = str(r).replace(',','').replace('[','').replace(']','')
print(r)

