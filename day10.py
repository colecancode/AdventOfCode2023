from collections import deque

def left(c): return c in "-J7"
def right(c): return c in "-FL"
def up(c): return c in "|JL"
def down(c): return c in "|F7"

def solve(part):
    grid = []
    while line := input():
        grid.append("."+line+".")
    
    m = len(grid[0])
    grid = ["."*m] + grid + ["."*m]
    n = len(grid)

    sr, sc = 0, 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'S':
                sr, sc = i, j

    if left(grid[sr][sc+1]) and right(grid[sr][sc-1]):
        grid[sr] = grid[sr][:sc] + '-' + grid[sr][sc+1:]
    if up(grid[sr+1][sc]) and down(grid[sr-1][sc]):
        grid[sr] = grid[sr][:sc] + '|' + grid[sr][sc+1:]
    if left(grid[sr][sc+1]) and down(grid[sr - 1][sc]):
        grid[sr] = grid[sr][:sc] + 'L' + grid[sr][sc+1:]
    if right(grid[sr][sc-1]) and down(grid[sr-1][sc]):
        grid[sr] = grid[sr][:sc] + 'J' + grid[sr][sc+1:]
    if right(grid[sr][sc-1]) and up(grid[sr+1][sc]):
        grid[sr] = grid[sr][:sc] + '7' + grid[sr][sc+1:]
    if left(grid[sr][sc+1]) and up(grid[sr+1][sc]):
        grid[sr] = grid[sr][:sc] + 'F' + grid[sr][sc+1:]

    isloop = [[False] * m for _ in range(n)]
    bfs = deque([(sr, sc)])
    steps = 0
    cpy = grid.copy()
    while bfs:
        steps += 1
        k = len(bfs)
        for _ in range(k):
            r, c = bfs.popleft()
            isloop[r][c] = True
            if left(cpy[r][c]) and cpy[r][c-1] != '.':
                bfs.append((r, c-1))
            if right(cpy[r][c]) and cpy[r][c+1] != '.':
                bfs.append((r, c+1))
            if up(cpy[r][c]) and cpy[r-1][c] != '.':
                bfs.append((r-1, c))
            if down(cpy[r][c]) and cpy[r+1][c] != '.':
                bfs.append((r+1, c))
            cpy[r] = cpy[r][:c] + '.' + cpy[r][c+1:]

    if part == 1:
        print(steps - 1)
    else:
        area = 0
        inloop = False
        lastpipe = '.'
        for i in range(n):
            for j in range(m):
                if isloop[i][j]:
                    if grid[i][j] in "|FL":
                        inloop = not inloop
                    elif grid[i][j] == '7' and lastpipe == 'F':
                        inloop = not inloop
                    elif grid[i][j] == 'J' and lastpipe == 'L':
                        inloop = not inloop

                    if grid[i][j] != '-':
                        lastpipe = grid[i][j]
                elif inloop:
                    area += 1

        print(area)

solve(1)
solve(2)
