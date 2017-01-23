t = int(input())

while t:
	t -= 1
	u = int(input())

	users = input().split()

	c = int(input())
	
	chats = ['afjdbaslkkgabsd glasdblg']
	for i in range(c):
		chats.append(input())
		chats[i+1] = chats[i+1].split(':', 1)
	chats.append('afjdbaslkkgabsd glasdblg')

	flag = 1

	for i in range(1, c+1):
		if(chats[i][0] == '?'):
			for j in range(u):
				a = not (users[j] in chats[i-1][0])
				b = not (users[j] in chats[i][1])
				d = not (users[j] in chats[i+1][0])

				if(a and b and d):
					chats[i][0] = users[j]
					break

		if(chats[i][0] == '?'):
			flag = 0
			break
		else:
			pass

	if flag:
		for i in range(c):
			print(':'.join(chats[i+1]))
	else:
		print("Impossible")