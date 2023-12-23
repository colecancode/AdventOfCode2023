from collections import *

bricks = []
while line := input():
    bricks.append([[int(i) for i in j.split(',')] for j in line.split('~')])
bricks.sort(key=lambda a: a[0][2])

seen = {}
supporting = [set() for i in range(len(bricks))]
supported = [set() for i in range(len(bricks))]
for i in range(len(bricks)):
    x1, y1, z1 = bricks[i][0]
    x2, y2, z2 = bricks[i][1]

    offset = 1
    while min(z1, z2) - offset > 0:
        for x in range(min(x1, x2), max(x1, x2) + 1):
            for y in range(min(y1, y2), max(y1, y2) + 1):
                z = min(z1, z2) - offset
                if (x, y, z) in seen:
                    supported[i].add(seen[(x, y, z)])
        if supported[i]:
            break
        offset += 1
    offset -= 1

    for x in supported[i]:
        supporting[x].add(i)

    for x in range(min(x1, x2), max(x1, x2) + 1):
        for y in range(min(y1, y2), max(y1, y2) + 1):
            for z in range(min(z1, z2), max(z1, z2) + 1):
                seen[(x, y, z - offset)] = i

part1, part2 = 0, 0
for i in range(len(bricks)):
    critical = False
    for j in supporting[i]:
        if len(supported[j]) == 1:
            critical = True
    if not critical:
        part1 += 1

    a = set([i])
    while True:
        progress = False
        add = set()
        for l in a:
            for j in supporting[l]:
                if j in a:
                    continue
                if all([k in a for k in supported[j]]):
                    add.add(j)
                    progress = True
        if not progress:
            break
        a = a | add
    part2 += len(a) - 1

print(part1)
print(part2)