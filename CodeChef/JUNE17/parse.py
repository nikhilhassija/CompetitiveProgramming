d = {}
d["1.581976706869326"] = []
d["2.718281828459046"] = []

for i in range(200):
	a, b = input().split()
	d[a].append(int(b))

print(d)
print(len(d["1.581976706869326"]))
print(len(d["2.718281828459046"]))