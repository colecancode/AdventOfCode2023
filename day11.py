def solve(value):
	grid = []
	while line := input():
		grid.append(line)

	n, m = len(grid), len(grid[0])
	row = [True for _ in range(n)]
	col = [True for _ in range(m)]
	arr = []
	for r in range(n):
		for c in range(m):
			row[r] &= grid[r][c] == "."
			col[c] &= grid[r][c] == "."
			if grid[r][c] == "#":
				arr.append([r, c])
	
	ans = 0
	for i in range(len(arr)):
		for j in range(i+1, len(arr)):
			r, c = arr[i]
			R, C = arr[j]
			
			if r > R: r, R = R, r
			if c > C: c, C = C, c

			for k in range(r, R):
				if row[k]: ans += value
				else: ans += 1
			for k in range(c, C):
				if col[k]: ans += value
				else: ans += 1
	print(ans)

solve(2)
solve(1000000)