bag = []
Q = int(input())
for _ in range(Q):
	query = list(map(int, input().split()))
	if query[0] == 1:
		x = query[1]
		bag.append(x)
	elif query[0] == 2:
		bag.sort()
		print(bag[0])
		bag = bag[1:]
