inp = []
while line := input():
	inp.append(list(line))

slope = {
	(0, 1) : '<',
	(0, -1) : '>',
	(1, 0) : '^',
	(-1, 0) : 'v'
}
for part in range(1, 2+1):
	grid = [row.copy() for row in inp]
	n = len(grid)
	nodes = [[]]
	def init(r, c, node):
		weight = 0
		while True:
			weight += 1
			neighbors = list(filter(
				lambda p : 0 <= r+p[0] < n and 0 <= c+p[1] < n and grid[r+p[0]][c+p[1]] not in ['#', node],
				[(0, 1), (0, -1), (1, 0), (-1, 0)])
				)

			if len(neighbors) == 1:
				grid[r][c] = node
				r += neighbors[0][0]
				c += neighbors[0][1]
			else:
				if grid[r][c] == '.':
					nodes.append([])
					new_node = len(nodes)-1
					grid[r][c] = new_node
					for dr, dc in neighbors:
						if type(grid[r+dr][c+dc]) == int or grid[r+dr][c+dc] == slope[(dr, dc)]:
							continue
						init(r+dr, c+dc, new_node)
				nodes[node].append((grid[r][c], weight))
				if (part == 2):
					nodes[grid[r][c]].append((node, weight))
				break

	init(0, 1, 0)
	vis = [False for _ in range(len(nodes))]
	ans = 0
	def dfs(node, cost):
		global ans
		if node and len(nodes[node]) == part-1:
			ans = max(ans, cost)
		elif not vis[node]:
			vis[node] = True
			for next_node, weight in nodes[node]:
				dfs(next_node, cost+weight)
			vis[node] = False

	dfs(0, 0)
	print(ans-1)