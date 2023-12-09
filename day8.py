import math

def part1():
    directions = input()
    input()

    adj = {}
    while line := input():
        adj[line[:3]] = (line[7:10], line[12:15])

    node = "AAA"
    steps, i = 0, 0
    while node != "ZZZ":
        node = adj[node][0 if directions[i] == "L" else 1]
        steps += 1
        i = (i+1) % len(directions)
    print(steps)

# this LCM solution shouldn't work, but the problem author restricts input without revealing it
def part2():
    directions = input()
    input()

    adj = {}
    while line := input():
        adj[line[:3]] = (line[7:10], line[12:15])

    ans = 1
    for node in adj.keys():
        if node[2] != "A": continue
        steps, i = 0, 0
        while node[2] != "Z":
            node = adj[node][0 if directions[i] == "L" else 1]
            steps += 1
            i = (i+1) % len(directions)
        ans = math.lcm(ans, steps)
    print(ans)

part1()
part2()