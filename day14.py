# rocks roll north
def tilt(grid):
	n = len(grid)
	for c in range(n):
		ptr = 0
		for r in range(n):
			if grid[r][c] == "#":
				ptr = r+1# rocks roll north
def tilt(grid):
	n = len(grid)
	for c in range(n):
		ptr = 0
		for r in range(n):
			if grid[r][c] == "#":
				ptr = r+1
			elif grid[r][c] == "O":
				grid[r][c] = "."
				grid[ptr][c] = "O"
				ptr += 1

# calculate load
def load(grid):
	n, ret = len(grid), 0
	for r in range(n):
		for c in range(n):
			if grid[r][c] == "O":
				ret += n-r
	return ret

# hashable representation
def getkey(grid):
	return "\n".join(["".join(x) for x in grid])

def part1():
	grid = []
	while line := input():
		grid.append(list(line))

	tilt(grid)
	print(load(grid))

def part2():
	grid = []
	while line := input():
		grid.append(list(line))

	t = 1e9
	memo = {}
	memo[getkey(grid)] = t
	while t > 0:
		t -= 1
		for i in range(4):
			tilt(grid)
			grid = [list(x)[::-1] for x in zip(*grid)] # rotate clockwise
		
		key = getkey(grid)
		if key in memo:
			t %= memo[key] - t
		memo[key] = t
	print(load(grid))

part1()
part2()
			elif grid[r][c] == "O":
				grid[r][c] = "."
				grid[ptr][c] = "O"
				ptr += 1

# calculate load
def load(grid):
	n, ret = len(grid), 0
	for r in range(n):
		for c in range(n):
			if grid[r][c] == "O":
				ret += n-r
	return ret

# hashable representation
def getkey(grid):
	return "\n".join(["".join(x) for x in grid])

def part1():
	grid = []
	while line := input():
		grid.append(list(line))

	tilt(grid)
	print(load(grid))

def part2():
	grid = []
	while line := input():
		grid.append(list(line))

	t = 1e9
	memo = {}
	memo[getkey(grid)] = t
	while t > 0:
		t -= 1
		for i in range(4):
			tilt(grid)
			grid = [list(x)[::-1] for x in zip(*grid)] # rotate clockwise
		
		key = getkey(grid)
		if key in memo:
			t %= memo[key] - t
		memo[key] = t
	print(load(grid))

part1()
part2()