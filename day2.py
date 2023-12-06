from collections import *

def part1():
    ans = 0
    cap = {
        "red": 12,
        "green": 13,
        "blue": 14
    }
    while line := input():
        game, data = line.split(":")
        game = int(game.split()[1])
        flag = True
        for draw in data.split(";"):
            for color in draw.split(","):
                amt, clr = color.split()
                flag &= int(amt) <= cap[clr]
        if flag:
            ans += game
    print(ans)

def part2():
    ans = 0
    while line := input():
        game, data = line.split(":")
        floor = defaultdict(int)
        for draw in data.split(";"):
            for color in draw.split(","):
                amt, clr = color.split()
                floor[clr] = max(floor[clr], int(amt))
        ans += floor["red"] * floor["green"] * floor["blue"]
    print(ans)

part1()
part2()