#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)
#define ll long long

void part1() {
	int ans = 0;
	vector<string> grid;
	INPUT(line) {
		grid.push_back(line);
		grid.back().push_back('.');
	}
	int n = grid.size();
	int m = grid[0].size();
	grid.insert(begin(grid), string(m, '.'));
	grid.push_back(string(m, '.'));

	FOR(r, 1, n+1) {
		int s = -1;
		FOR(c, 0, m) {
			if (isdigit(grid[r][c])) {
				if (s == -1)
					s = c;
			}
			else if (s != -1) {
				bool flag = 0;
				FOR(i, max(0, s-1), c+1)
					FOR(dr, -1, 1+1)
						flag |= !isdigit(grid[r+dr][i]) && grid[r+dr][i] != '.';

				if (flag)
					ans += stoi(grid[r].substr(s, c-s));
				s = -1;
			}
		}
	}
	cout << ans << '\n';
}

void part2() {
	vector<string> grid;
	INPUT(line) {
		grid.push_back(line);
		grid.back().push_back('.');
	}
	int n = grid.size();
	int m = grid[0].size();
	grid.insert(begin(grid), string(m, '.'));
	grid.push_back(string(m, '.'));

	vector<vector<ll>> cnt(n+2, vector<ll>(m)), ratio(n, vector<ll>(m, 1));
	FOR(r, 1, n+1) {
		int s = -1;
		FOR(c, 0, m) {
			if (isdigit(grid[r][c])) {
				if (s == -1)
					s = c;
			}
			else if (s != -1) {
				ll num = stoi(grid[r].substr(s, c-s));
				FOR(i, max(0, s-1), c+1)
					FOR(dr, -1, 1 + 1)
						if (grid[r+dr][i] == '*')
							++cnt[r+dr][i], ratio[r+dr][i] *= num;
				s = -1;
			}
		}
	}
	ll ans = 0;
	FOR(r, 1, n+1)
		FOR(c, 1, m-1)
		 if (cnt[r][c] == 2)
			 ans += ratio[r][c];
	cout << ans << '\n';
}

int main() {
	part1();
	part2();
}