from math import *

def part1():
    time = [int(t) for t in input().split()[1:]]
    dist = [int(d) for d in input().split()[1:]]

    ans = 1
    for i in range(len(time)):
        discriminant = sqrt(time[i]*time[i] - 4*dist[i])
        high = ceil((time[i] + discriminant)/2) - 1
        low = floor((time[i] - discriminant)/2) + 1
        ans *= high - low + 1;
    print(ans)

def part2():
    time = int("".join(input().split()[1:]))
    dist = int("".join(input().split()[1:]))

    discriminant = sqrt(time*time - 4*dist)
    high = ceil((time + discriminant)/2) - 1
    low = floor((time - discriminant)/2) + 1
    print(high - low + 1)

part1()
part2()