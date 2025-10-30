S = input()
T = list(S)
flag = False
for i in range(len(S)):
	if S[i] == ".": 
		if not flag:
			T[i] = "o"
			flag = True
		else:
			T[i] = "."
	else:
		T[i] = "#"
		flag = False
print("".join(T))

# S := ...#..#.##.#.
# nS = #...#..#.##.#.
# ans = #o..#o.#o##o#o
# nans = o..#o.#o##o#o <- これが出力される
# print(("#" + input()).replace("#.", "#o")[1:])
