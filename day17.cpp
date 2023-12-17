#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

int dir[5]{ 0, 1, 0, -1, 0 };
void solve(int minstep, int maxstep) {
	vector<string> grid;
	INPUT(line) grid.push_back(line);

	int n = size(grid), m = size(grid[0]);
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, { INT_MAX, INT_MAX }));
	priority_queue<tuple<int, int, int, bool>> pq;
	pq.push({ 0, 0, 0, 0 });
	pq.push({ 0, 0, 0, 1 });
	dist[0][0][0] = dist[0][0][1] = 0;
	while (!pq.empty()) {
		auto [cost, r, c, horizontal] = pq.top(); pq.pop();
		cost *= -1;
		if (cost != dist[r][c][horizontal]) continue;
		FOR(i, 1, 5) {
			if (horizontal == (dir[i] != 0)) continue; // same direction
			int R = r, C = c;
			int newcost = cost;
			FOR(j, 1, maxstep+1) {
				R += dir[i-1], C += dir[i];
				if (R < 0 || R == n || C < 0 || C == m) break;
				newcost += grid[R][C] - '0';
				if (j >= minstep && newcost < dist[R][C][!horizontal]) {
					dist[R][C][!horizontal] = newcost;
					pq.push({ -newcost, R, C, !horizontal });
				}
			}
		}
	}
	cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]) << '\n';
}

int main() {
	solve(1, 3);
	solve(4, 10);
}