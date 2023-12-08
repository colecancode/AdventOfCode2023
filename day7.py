from collections import defaultdict

def score(hand, part):
	f = defaultdict(int)
	big, j_cnt = 0, 0
	for c in hand:
		if part == 2 and c == "J":
			j_cnt += 1
		else:
			f[c] += 1
			big = max(big, f[c])

	types = len(f)
	if part == 2:
		if j_cnt == 5:
			types = 1
		big += j_cnt

	if types == 1: scr = 6 # AAAAA
	elif types == 2 and big == 4: scr = 5 # AAAAB
	elif types == 2: scr = 4 # AAABB
	elif types == 3 and big == 3: scr = 3 # AAABC
	elif types == 3: scr = 2 # AABBC
	elif types == 4: scr = 1 # AABCD
	else: scr = 0 # ABCDE

	order = "23456789TJQKA" if part == 1 else "J23456789TQKA"
	for c in hand:
		scr = scr*13 + order.find(c)
	return scr

def solve(part):
	hands = []
	while line := input():
		hand, bid = line.split()
		hands.append([score(hand, part), int(bid)])
	hands.sort()
	ans = 0
	for i in range(len(hands)):
		ans += (i+1)*hands[i][1]
	print(ans)

solve(1)
solve(2)