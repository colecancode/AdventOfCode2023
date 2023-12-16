#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)
typedef tuple<int, int, int, int> beam;

int bit(int dr, int dc) {
	if (dr == -1) return 1 << 0;
	if (dr == 1) return 1 << 1;
	if (dc == -1) return 1 << 2;
	return 1 << 3;
}

int solve(int R, int C, int DR, int DC, vector<string>& grid) {
	int n = size(grid), m = size(grid[0]);
	queue<beam> bfs;
	bfs.push({ R, C, DR, DC });
	vector<vector<int>> vis(n, vector<int>(m));
	while (!bfs.empty()) {
		beam b = bfs.front(); bfs.pop();
		auto& [r, c, dr, dc] = b;
		if (r < 0 || c < 0 || r == n || c == m || vis[r][c] & bit(dr, dc))
			continue;
		vis[r][c] |= bit(dr, dc);

		if (grid[r][c] == '\\')
			swap(dr, dc);
		else if (grid[r][c] == '/')
			swap(dr *= -1, dc *= -1);
		else if (grid[r][c] == '|' && dc)
			bfs.push({ r-1, c, -1, 0 }),
			dr = 1,
			dc = 0;
		else if (grid[r][c] == '-' && dr)
			bfs.push({ r, c-1, 0, -1 }),
			dr = 0,
			dc = 1;

		bfs.push({ r+dr, c+dc, dr, dc });
	}
	int ans = 0;
	FOR(i, 0, n)
		FOR(j, 0, m)
			if (vis[i][j])
				++ans;
	return ans;
}

void part1() {
	vector<string> grid;
	INPUT(line) grid.push_back(line);
	cout << solve(0, 0, 0, 1, grid) << '\n';
}

void part2() {
	vector<string> grid;
	INPUT(line) grid.push_back(line);

	int n = size(grid), m = size(grid[0]);
	int ans = 0;
	FOR(i, 0, n)
		ans = max({ ans, solve(i, 0, 0, 1, grid), solve(i, m-1, 0, -1, grid) });
	FOR(i, 0, n)
		ans = max({ ans, solve(0, i, 1, 0, grid), solve(n-1, i, -1, 0, grid) });
	cout << ans << '\n';
}

int main() {
	part1();
	part2();
}