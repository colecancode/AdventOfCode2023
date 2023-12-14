#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

// rocks roll north
void tilt(vector<string>& grid) {
	int n = grid.size();
	FOR(c, 0, n) {
		int open = 0;
		FOR(r, 0, n) {
			if (grid[r][c] == '#')
				open = r + 1;
			else if (grid[r][c] == 'O')
				grid[r][c] = '.',
				grid[open++][c] = 'O';
		}
	}
}

// calculate load
int load(vector<string> grid) {
	int sum = 0;
	int n = grid.size();
	FOR(r, 0, n)
		FOR(c, 0, n)
		if (grid[r][c] == 'O')
			sum += n - r;
	return sum;
}

// rotate grid clockwise
vector<string> rotate(vector<string> grid) {
	int n = grid.size();
	vector<string> newgrid(n, string(n, ' '));
	FOR(r, 0, n)
		FOR(c, 0, n)
		newgrid[c][n - r - 1] = grid[r][c];
	return newgrid;
}

void part1() {
	vector<string> grid;
	INPUT(line) grid.push_back(line);

	tilt(grid);
	cout << load(grid) << '\n';
}

void part2() {
	vector<string> grid;
	INPUT(line) grid.push_back(line);

	map<vector<string>, int> memo;
	memo[grid] = 1e9;
	for (int t = 1e9; t-- > 0;) {
		for (int i = 4; i--;) {
			tilt(grid);
			grid = rotate(grid);
		}
		auto it = memo.find(grid);
		if (it != end(memo))
			t %= it->second - t;
		else
			memo[grid] = t;
	}
	cout << load(grid) << '\n';
}

int main() {
	part1();
	part2();
}