#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void solve(int part) {
	vector<pair<int, int>> points;
	int r = 0, c = 0;
	long long area = 0;
	INPUT(line) {
		int i = line.find('(');

		stringstream ss(line);
		char dir; ss >> dir;
		int amt; ss >> amt;
		if (part == 2) {
			string code; ss >> code;
			dir = code[code.size()-2];
			amt = stoi(code.substr(2, code.size()-4), 0, 16);
		}
		area += amt;

		if (dir == '0' || dir == 'R') c += amt;
		else if (dir == '1' || dir == 'D') r += amt;
		else if (dir == '2' || dir == 'L') c -= amt;
		else if (dir == '3' || dir == 'U') r -= amt;
		points.push_back({ r, c });
	}

	int n = size(points);
	int j = n-1;
	FOR(i, 0, n) {
		area += (long long)(points[j].first + points[i].first) * (points[j].second - points[i].second);
		j = i;
	}
	cout << area/2 + 1 << '\n';
}

int main() {
	solve(1);
	solve(2);
}