def ispal(x):
	x = str(x)
	if(x == x[::-1]):
		return True
	return False

p = 0
for i in range(100,1000):
	for j in range(100,1000):
		if(ispal(i*j)):
			p = max(p,i*j)
print(p)