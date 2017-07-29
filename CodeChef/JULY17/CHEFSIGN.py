t = int(input())
for _ in range(t):
	print((lambda x: max(max([i.count("<") for i in x.split(">")]), max([i.count(">") for i in x.split("<")])) + 1)(input().replace("=","")))