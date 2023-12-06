def part1():
    ans = 0
    while line := input():
        card, data = line.split(":")
        winners, given = data.split("|")
        winners = set(winners.split())

        val = 1
        for num in given.split():
            if num in winners:
                val *= 2
        ans += int(val/2)
    print(ans)

def part2():
    ans = 0
    cards = [1 for i in range(500)]
    while line := input():
        card, data = line.split(":")
        card = int(card[5:])
        winners, given = data.split("|")
        winners = set(winners.split())

        ans += cards[card]
        cnt = 0
        for num in given.split():
            if num in winners:
                cnt += 1
        for i in range(1, cnt+1):
            cards[card+i] += cards[card]
    print(ans)

part1()
part2()