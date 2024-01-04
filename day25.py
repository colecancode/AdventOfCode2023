# pip import networkx
import networkx as nx
from itertools import combinations

graph = nx.Graph()
while line := input():
    node1, connected = line.split(': ')
    for node2 in connected.split():
        graph.add_edge(node1, node2, capacity=1)

for n, m in combinations(graph.nodes, 2):
    cuts, partitions = nx.minimum_cut(graph, n, m)
    if cuts == 3:
        print(len(partitions[0])*len(partitions[1]))
        break