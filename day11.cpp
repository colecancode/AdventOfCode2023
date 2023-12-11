#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void solve(int value) {
	vector<string> grid;
	INPUT(line) grid.push_back(line);

	int n = size(grid), m = size(grid[0]);
	vector<bool> row(n, true), col(m, true);
	vector<pair<int, int>> arr;
	FOR(r, 0, n)
	FOR(c, 0, m) {
		row[r] = row[r] && grid[r][c] == '.';
		col[c] = col[c] && grid[r][c] == '.';
		if (grid[r][c] == '#') arr.push_back({ r, c });
	}
	
	long long ans = 0;
	FOR(i, 0, arr.size())
	FOR(j, i+1, arr.size()) {
		auto [r, c] = arr[i];
		auto [R, C] = arr[j];
		if (r > R) swap(r, R);
		if (c > C) swap(c, C);
		FOR(k, r, R) {
			if (row[k]) ans += value;
			else ++ans;
		}
		FOR(k, c, C) {
			if (col[k]) ans += value;
			else ++ans;
		}
	}
	cout << ans << '\n';
}

void main() {
	solve(2);
	solve(1000000);
}