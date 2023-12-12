#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

bool left(char c) { return string("-J7").find(c) != -1; }
bool right(char c) { return string("-FL").find(c) != -1; }
bool up(char c) { return string("|JL").find(c) != -1; }
bool down(char c) { return string("|F7").find(c) != -1; }

void solve(int part) {
	vector<string> grid;
	INPUT(line)
		grid.push_back("."+line+".");
	int m = size(grid[0]);
	grid.insert(begin(grid), string(m, '.'));
	grid.push_back(string(m, '.'));
	int n = size(grid);

	int sr, sc;
	FOR(i, 0, n)
		FOR(j, 0, m)
			if (grid[i][j] == 'S')
				sr = i, sc = j;

	if (left(grid[sr][sc+1]) && right(grid[sr][sc-1])) grid[sr][sc] = '-';
	if (up(grid[sr+1][sc]) && down(grid[sr-1][sc])) grid[sr][sc] = '|';
	if (left(grid[sr][sc+1]) && down(grid[sr-1][sc])) grid[sr][sc] = 'L';
	if (right(grid[sr][sc-1]) && down(grid[sr-1][sc])) grid[sr][sc] = 'J';
	if (right(grid[sr][sc-1]) && up(grid[sr+1][sc])) grid[sr][sc] = '7';
	if (left(grid[sr][sc+1]) && up(grid[sr+1][sc])) grid[sr][sc] = 'F';

	vector<vector<bool>> isloop(n, vector<bool>(m));
	queue<pair<int, int>> bfs;
	vector<string> cpy = grid;
	bfs.push({ sr, sc });
	int steps = 0;
	while (!bfs.empty()) {
		++steps;
		int k = bfs.size();
		while (k--) {
			auto [r, c] = bfs.front(); bfs.pop();
			isloop[r][c] = true;
			if (left(cpy[r][c]) && cpy[r][c-1] != '.') bfs.push({ r, c-1 });
			if (right(cpy[r][c]) && cpy[r][c+1] != '.') bfs.push({ r, c+1 });
			if (up(cpy[r][c]) && cpy[r-1][c] != '.') bfs.push({ r-1, c });
			if (down(cpy[r][c]) && cpy[r+1][c] != '.') bfs.push({ r+1, c });
			cpy[r][c] = '.';
		}
	}

	if (part == 1) {
		cout << steps-1 << '\n';
	}
	else {
		int area = 0;
		bool inloop = false;
		char lastpipe = '.';
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				if (isloop[i][j]) {
					if (string("|FL").find(grid[i][j]) != -1) inloop = !inloop;
					else if (grid[i][j] == '7' && lastpipe == 'F') inloop = !inloop;
					else if (grid[i][j] == 'J' && lastpipe == 'L') inloop = !inloop;
					
					if (grid[i][j] != '-') lastpipe = grid[i][j];
				}
				else if (inloop) ++area;
			}
		}
		cout << area << '\n';
	}
}

int main() {
	solve(1);
	solve(2);
}