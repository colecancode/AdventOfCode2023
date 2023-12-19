import copy

ans = 0
workflow = {}

def dfs(cur, part, version):
    global ans
    if cur == "A":
        if version == 1:
            for val in part:
                ans += val
        else:
            add = 1
            for l, r in part:
                add *= r - l + 1
            ans += add
        return
    if cur == "R":
        return

    for condition in workflow[cur][:-1]:
        i = "xmas".find(condition[0])
        num, next = condition[2:].split(":")
        num = int(num)
        if condition[1] == ">":
            if version == 1:
                if part[i] > num:
                    dfs(next, part, version)
                    return
            elif part[i][1] > num:
                cpy = copy.deepcopy(part)
                cpy[i][0] = num+1
                dfs(next, cpy, version)
                part[i][1] = num
        else:
            if version == 1:
                if part[i] < num:
                    dfs(next, part, version)
                    return
            elif part[i][0] < num:
                cpy = copy.deepcopy(part)
                cpy[i][1] = num-1
                dfs(next, cpy, version)
                part[i][0] = num
    
    dfs(workflow[cur][-1], part, version)

def solve(version):
    global ans, workflow
    ans = 0
    workflow = {}
    while line := input():
        name, data = line.split("{")
        workflow[name] = data[:-1].split(',')

    parts = []
    while line := input():
        parts.append([])
        a = line[:-1].split("=")
        for i in range(1, 5):
            parts[-1].append(int(a[i].split(",")[0]))

    if version == 1:
        for part in parts:
            dfs("in", part, 1)
    else:
        dfs("in", [[1, 4000], [1, 4000], [1, 4000], [1, 4000]], 2)

    print(ans)

solve(1)
solve(2)