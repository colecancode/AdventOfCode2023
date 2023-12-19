def solve(part):
	points = []
	r, c, area = 0, 0, 0
	while line := input():
		dir, amt, code = line.split()
		amt = int(amt)

		if part == 2:
			dir = code[-2];
			amt = int(code[2:-2], 16);
		area += amt;

		if dir in "0R": c += amt;
		elif dir in "1D": r += amt;
		elif dir in "2L": c -= amt;
		elif dir in "3U": r -= amt;
		points.append((r, c))

	j = len(points)-1
	for i in range(len(points)):
		area += (points[j][0] + points[i][0]) * (points[j][1] - points[i][1])
		j = i
	print(area//2 + 1)

solve(1)
solve(2)