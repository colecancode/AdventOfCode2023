def part1():
    ans = 0
    while line := input():
        first, last = "", ""
        for c in line:
            if c.isdigit():
                if not first:
                    first = c
                last = c
        ans += int(first+last)
    print(ans)

def part2():
    ans = 0
    while line := input():
        first, last = "", ""
        for i in range(len(line)):
            if line[i].isdigit():
                if not first:
                    first = line[i]
                last = line[i]
            else:
                for value, string in enumerate(["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"], 1):
                    if line[i:i+len(string)] == string:
                        if not first:
                            first = str(value)
                        last = str(value)
        ans += int(first+last)
    print(ans)

part1()
part2()