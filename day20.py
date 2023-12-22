from collections import deque, defaultdict
from math import lcm

modules = {}
feeder = ""
while line := input():
    name, adj = line.split(" -> ")
    adj = adj.split(", ")

    if name == "broadcaster":
        modules[name] = ("", adj)
    else:
        module_type = name[0]
        name = name[1:]
        modules[name] = (module_type, adj)
    
    if "rx" in adj:
        feeder = name

waiting = set()
ff_state = defaultdict(bool)
c_state = defaultdict(set)

for name, data in modules.items():
    for next in data[1]:
        if next == "rx": continue
        if modules[next][0] == "&":
            c_state[name].add(name)
        if next == feeder:
            waiting.add(name)

low, high, t, cycle_lcm = 0, 0, 0, 1
while True:
    t += 1
    bfs = deque([("broadcaster", "button", False)])
    while bfs:
        name, parent, pulse = bfs.popleft()
        if pulse: high += 1
        else: low += 1

        if name == "rx": continue
        module_type, adj = modules[name]
        if module_type == '%':
            if pulse: continue
            ff_state[name] = not ff_state[name]
            pulse = ff_state[name]
        elif module_type == '&':
            if pulse:
                c_state[name].discard(parent)
            else:
                c_state[name].add(parent)
            pulse = len(c_state[name]) > 0

        if pulse and name in waiting:
            waiting.remove(name)
            cycle_lcm = lcm(cycle_lcm, t)
            if not waiting:
                print(cycle_lcm)
                exit(0)

        for next_item in adj:
            bfs.append((next_item, name, pulse))

    if t == 1000:
        print(low * high)
