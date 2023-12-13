def solve(part):
    ans = 0
    while pattern := input():
        grid = [pattern]
        while line := input():
            grid.append(line)

        n, m = len(grid), len(grid[0])
        stop = False
        for r in range(1, n):
            if stop: break
            bad = 0
            for i in range(r, min(n, 2*r)):
                for j in range(0, m):
                    if grid[i][j] != grid[2*r-i-1][j]:
                        bad += 1

            if bad+1 == part:
                ans += r*100;
                stop = True;

        for c in range(1, m):
            if stop: break
            bad = 0
            for i in range(0, n):
                for j in range(c, min(m, 2*c)):
                    if grid[i][j] != grid[i][2*c-j-1]:
                        bad += 1

            if bad+1 == part:
                ans += c;
                stop = True;
    print(ans)

solve(1)
solve(2)