def get_hash(s):
    ret = 0
    for c in s:
        ret = (ret + ord(c)) * 17 % 256
    return ret

def part1():
    ans = 0
    with open("in.txt", "r") as file:
        input_str = file.read()
        for line in input_str.split(','):
            ans += get_hash(line)
    print(ans)

def part2():
    boxes = [[] for _ in range(256)]
    with open("in.txt", "r") as file:
        input_str = file.read()
        for line in input_str.split(','):
            if line[-1] == '-':
                line = line[:-1]
                box = get_hash(line)
                for k, (key, _) in enumerate(boxes[box]):
                    if key == line:
                        del boxes[box][k]
                        break
            else:
                key, lens = line.split("=")
                lens = int(lens)
                box = get_hash(key)
                flag = True
                for k, (existing_key, _) in enumerate(boxes[box]):
                    if existing_key == key:
                        boxes[box][k] = [key, lens]
                        flag = False
                        break
                if flag:
                    boxes[box].append([key, lens])

    ans = 0
    for i in range(256):
        for j, (_, value) in enumerate(boxes[i]):
            ans += (i + 1) * value * (j + 1)
    print(ans)

part1()
part2()
