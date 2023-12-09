def solve(part):
    ans = 0
    while line := input():
        arr = [[int(x) for x in line.split()]]
        while True:
            arr.append([])
            flag = True
            for i in range(1, len(arr[-2])):
                flag &= arr[-2][i] == arr[-2][i-1]
                arr[-1].append(arr[-2][i] - arr[-2][i-1])
            if flag: break

        for i in range(len(arr)-1, 0, -1):
            if part == 1:
                arr[i-1].append(arr[i][-1] + arr[i-1][-1])
            else:
                arr[i-1].append(arr[i-1][0] - arr[i][-1])
        ans += arr[0][-1]
    print(ans)

solve(1)
solve(2)