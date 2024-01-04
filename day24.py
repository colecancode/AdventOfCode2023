#pip import z3-solver
from z3 import *

rocks = []
while line := input():
	rocks.append([list(map(int, xyz.split(','))) for xyz in line.split(' @ ')])

# part 1
collisions = 0
for i in range(len(rocks)):
	for j in range(i+1, len(rocks)):
		p1, v1 = rocks[i]
		p2, v2 = rocks[j]

		div = v2[1] - v1[1] * v2[0] / v1[0]
		if div:
			t2 = (p1[1] - p2[1] + v1[1] * (p2[0] - p1[0]) / v1[0]) / div
			t1 = (p2[0] - p1[0] + v2[0] * t2) / v1[0]
			if t1 >= 0 and t2 >= 0 and 2e14 <= p1[0] + v1[0] * t1 <= 4e14 and 2e14 <= p1[1] + v1[1] * t1 <= 4e14:
				collisions += 1
print(collisions)

# part 2
EQ = Solver()
POS = Ints('x y z')
VEL = Ints('vx vy vz')
TIME = Ints('t1 t2 t3')

for i in range(3):
	pos, vel = rocks[i]
	for j in range(3):
		EQ.add(pos[j] + vel[j] * TIME[i] == POS[j] + VEL[j] * TIME[i])

EQ.check()
SOL = EQ.model()
print(sum([SOL[v].as_long() for v in POS]))