s = input()

M = {'R': 0, 'G': 0, 'B': 0, 'Y': 0}

while('!' in s):
	#left pass
	for i in range(len(s)-4):
		t = s[i:i+4]
		p = t

		if t.count('!') == 1:
			if(t.count('R') == 0):
				p = t.replace('!', 'R')
				M['R'] = M['R'] + 1
			if(t.count('G') == 0):
				p = t.replace('!', 'G')
				M['G'] = M['G'] + 1
			if(t.count('B') == 0):
				p = t.replace('!', 'B')
				M['B'] = M['B'] + 1
			if(t.count('Y') == 0):
				p = t.replace('!', 'Y')
				M['Y'] = M['Y'] + 1
		
		s = s[:i] + p + s[i+4:]

	for i in range(len(s)-4, 0, -1):
		t = s[i:i+4]
		p = t

		if t.count('!') == 1:
			if(t.count('R') == 0):
				p = t.replace('!', 'R')
				M['R'] = M['R'] + 1
			if(t.count('G') == 0):
				p = t.replace('!', 'G')
				M['G'] = M['G'] + 1
			if(t.count('B') == 0):
				p = t.replace('!', 'B')
				M['B'] = M['B'] + 1
			if(t.count('Y') == 0):
				p = t.replace('!', 'Y')
				M['Y'] = M['Y'] + 1
		
		s = s[:i] + p + s[i+4:]

print("{} {} {} {}".format(M['R'], M['B'], M['Y'], M['G']))