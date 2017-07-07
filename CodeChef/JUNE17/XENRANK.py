#!/usr/bin/python3 

t = int(input())

for _ in range(t):
	u, v = map(int, input().split())

	y = u + v

	x = (y * (y + 1)) // 2

	print(x + u + 1)