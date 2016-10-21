S = "0"

for i in range(1,10):
	S = S + str(i)*(len(S)+1) + S

print(S)