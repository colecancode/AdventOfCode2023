def part1():
    seeds = [int(s) for s in input().split()[1:]]
    input()
    for i in range(7):
        input()
        new_seeds = []
        while line := input():
            dest, source, size = map(int, line.split())
            for i in range(len(seeds)):
                if not seeds[i]:
                    continue
                if seeds[i] >= source and seeds[i] < source+size:
                    new_seeds.append(dest+seeds[i]-source)
                    seeds[i] = None
        for seed in seeds:
            if seed:
                new_seeds.append(seed)
        seeds = new_seeds
    print(min(*seeds))

def part2():
    seeds = [int(s) for s in input().split()[1:]]
    ranges = [[seeds[i], seeds[i]+seeds[i+1]-1] for i in range(0, len(seeds), 2)]
    input()
    for i in range(7):
        input()
        new_ranges = []
        while line := input():
            dest, source, size = map(int, line.split())
            for i in range(len(ranges)):
                if not ranges[i]:
                    continue
                
                l, r = ranges[i]
                if r < source or l >= source+size:
                    continue
                if l >= source and r < source+size:
                    new_ranges.append([dest+l-source, dest+r-source])
                    ranges[i] = None
                    continue
                L, R = max(l, source), min(r, source+size-1)
                new_ranges.append([dest+L-source, dest+R-source])
                if l < L:
                    ranges[i][1] = L-1
                else:
                    ranges[i] = None
                if r > R:
                    ranges.append([R+1, r])

        for rng in ranges:
            if rng:
                new_ranges.append(rng)
        ranges = new_ranges
    print(min(*[l for l,r in ranges]))

part1()
part2()