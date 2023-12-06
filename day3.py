def part1():
    grid = []
    while line := input():
        grid.append("."+line+".")
    m = len(grid[0])
    grid = ["."*m] + grid + ["."*m]
    n = len(grid)

    ans = 0
    for r in range(1, n-1):
        s = None
        for c in range(1, m):
            if grid[r][c].isdigit():
                if not s:
                    s = c
            elif s:
                flag = False
                for i in range(s-1, c+1):
                    for dr in range(-1, 1+1):
                        flag |= not grid[r+dr][i].isdigit() and grid[r+dr][i] != "."
                if flag:
                    ans += int(grid[r][s:c])
                s = None
    print(ans)

def part2():
    grid = []
    while line := input():
        grid.append("."+line+".")
    m = len(grid[0])
    grid = ["."*m] + grid + ["."*m]
    n = len(grid)

    cnt = [[0 for i in range(m)] for j in range(n)]
    mul = [[1 for i in range(m)] for j in range(n)]
    for r in range(1, n-1):
        s = None
        for c in range(1, m):
            if grid[r][c].isdigit():
                if not s:
                    s = c
            elif s:
                for i in range(s-1, c+1):
                    for dr in range(-1, 1+1):
                        if grid[r+dr][i] == "*":
                            cnt[r+dr][i] += 1
                            mul[r+dr][i] *= int(grid[r][s:c])
                s = None

    ans = 0
    for r in range(n):
        for c in range(m):
            if cnt[r][c] == 2:
                ans += mul[r][c]
    print(ans)
    

part1()
part2()