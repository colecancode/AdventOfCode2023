import heapq

def solve(minstep, maxstep):
    dir = [0, 1, 0, -1, 0]

    grid = []
    while line := input():
        grid.append(line)

    n, m = len(grid), len(grid[0])
    dist = [[[1e9, 1e9] for _ in range(m)] for _ in range(n)]

    pq = []
    heapq.heappush(pq, (0, 0, 0, False))
    heapq.heappush(pq, (0, 0, 0, True))
    dist[0][0][0] = dist[0][0][1] = 0
    while pq:
        cost, r, c, horizontal = heapq.heappop(pq)        
        if cost != dist[r][c][horizontal]:
            continue
        
        for i in range(1, 5):
            if horizontal == (dir[i] != 0):
                continue  # same direction
            
            R, C = r, c
            newcost = cost
            for j in range(1, maxstep+1):
                R += dir[i-1]
                C += dir[i]
                
                if R < 0 or R == n or C < 0 or C == m:
                    break
                
                newcost += int(grid[R][C])
                if j >= minstep and newcost < dist[R][C][not horizontal]:
                    dist[R][C][not horizontal] = newcost
                    heapq.heappush(pq, (newcost, R, C, not horizontal))
    
    print(min(dist[n-1][m-1][0], dist[n-1][m-1][1]))

solve(1, 3)
solve(4, 10)