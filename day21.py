from collections import deque
grid = []
while line := input():
    grid.append(list(line))

# only works on real input, not sample case
y = []
bfs = deque([(65, 65)])
seen = set(bfs)
valid = [0, 0]
for step in range(65 + 131*2+1):
    k = len(bfs)
    for i in range(k):
        r, c = bfs.popleft()
        valid[step % 2] += 1
        for dr, dc in ((0, 1), (0, -1), (1, 0), (-1, 0)):
            if grid[(r+dr)%131][(c+dc)%131] != '#' and (r+dr, c+dc) not in seen:
                bfs.append((r+dr, c+dc))
                seen.add((r+dr, c+dc))

    if (step - 65) % 131 == 0:
        y.append(valid[step % 2])
    if step == 64:
        print(valid[step % 2])

a = (y[2] - (2 * y[1]) + y[0]) // 2
b = y[1] - y[0] - a
c = y[0]

n = 26501300 // 131
print(a*n*n + b*n + c)