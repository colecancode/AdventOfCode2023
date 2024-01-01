#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)
typedef pair<int, int> ii;

map<ii, char> slope{
	{ {0, 1}, '<' },
	{ {0, -1}, '>' },
	{ {1, 0}, '^' },
	{ {-1, 0}, 'v' }
};

void init(int r, int c, int node, int part, vector<string>&grid, vector<vector<ii>>& nodes) {
	int weight = 0;
	while (1) {
		++weight;
		vector<ii> neighbors;
		for (auto [dr, dc] : vector<ii>{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} })
			if (r+dr >= 0 && r+dr < grid.size() && grid[r+dr][c+dc] != '#' && grid[r+dr][c+dc] != 'A'+node)
				neighbors.emplace_back(dr, dc);

		if (neighbors.size() == 1) {
			grid[r][c] = 'A'+node;
			r += neighbors[0].first;
			c += neighbors[0].second;
		}
		else {
			if (grid[r][c] == '.') {
				nodes.push_back({});
				int new_node = nodes.size()-1;
				grid[r][c] = 'A'+new_node;
				for (auto [dr, dc] : neighbors)
					if (string(".#<>^v").find(grid[r+dr][c+dc]) != -1 && grid[r+dr][c+dc] != slope[{dr, dc}])
						init(r+dr, c+dc, new_node, part, grid, nodes);
			}
			nodes[node].push_back({grid[r][c]-'A', weight});
			if (part == 2)
				nodes[grid[r][c]-'A'].push_back({node, weight});
			break;
		}
	}
}

void dfs(int node, int cost, int part, int& ans, vector<vector<ii>>& nodes, vector<bool>& vis) {
	if (node && nodes[node].size() == part - 1) {
		ans = max(ans, cost);
	}
	else if (!vis[node]){
		vis[node] = 1;
		for (auto [next_node, weight] : nodes[node])
			dfs(next_node, cost+weight, part, ans, nodes, vis);
		vis[node] = 0;
	}
}

int main() {
	vector<string> inp;
	INPUT(line) inp.push_back(line);

	FOR(part, 1, 2+1) {
		vector<string> grid = inp;
		vector<vector<ii>> nodes{ {} };
		init(0, 1, 0, part, grid, nodes);

		vector<bool> vis(nodes.size());
		int ans = 0;
		dfs(0, 0, part, ans, nodes, vis);
		cout << ans-1 << endl;
	}
}