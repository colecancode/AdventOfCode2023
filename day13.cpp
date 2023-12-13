#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void solve(int part) {
	long long ans = 0;
	while (cin.peek() != '\n') {
		vector<string> grid;
		INPUT(line) grid.push_back(line);

		int n = size(grid), m = size(grid[0]);
		bool stop = false;
		FOR(r, 1, n) {
			if (stop) break;
			int bad = 0;
			FOR(i, r, min(n, 2*r))
				FOR(j, 0, m)
					bad += grid[i][j] != grid[2*r-i-1][j];

			if (bad+1 == part) {
				ans += r*100;
				stop = true;
			}
		}
		FOR(c, 1, m) {
			if (stop) break;
			int bad = 0;
			FOR(i, 0, n)
				FOR(j, c, min(m, 2*c))
					bad += grid[i][j] != grid[i][2*c-j-1];

			if (bad + 1 == part) {
				ans += c;
				stop = true;
			}
		}
	}
	cin.get();
	cout << ans << '\n';
}

int main() {
	solve(1);
	solve(2);
}