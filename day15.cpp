#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

int gethash(string s) {
	int ret = 0;
	for (char c : s)
		ret = (ret + c) * 17 % 256;
	return ret;
}

void part1(string in) {
	int ans = 0;
	int n = in.size();
	for (int i = 0; i < n;) {
		int j = in.find(',', i);
		if (j == -1) j = n;
		string line = in.substr(i, j-i+1);
		i = j+1;
		if (i < n) line.pop_back();
		ans += gethash(line);
	}
	cout << ans << '\n';
}

void part2(string in) {
	vector<pair<string, int>> boxes[256];
	int n = in.size();
	for (int i = 0; i < n;) {
		int j = in.find(',', i);
		if (j == -1) j = n;
		string line = in.substr(i, j-i+1);
		i = j+1;
		if (i < n) line.pop_back();
		if (line.back() == '-') {
			line.pop_back();
			int box = gethash(line);
			FOR(i, 0, boxes[box].size()) {
				if (boxes[box][i].first == line) {
					boxes[box].erase(boxes[box].begin()+i);
					break;
				}
			}
		}
		else {
			int equals = line.find("=");
			string key = line.substr(0, equals);
			int lens = stoi(line.substr(equals+1));
			int box = gethash(key);
			bool flag = true;
			FOR(i, 0, boxes[box].size()) {
				if (boxes[box][i].first == key) {
					boxes[box][i].second = lens;
					flag = 0;
					break;
				}
			}
			if (flag)
				boxes[box].push_back({ key, lens });
		}
	}
	
	int ans = 0;
	FOR(i, 0, 256)
		FOR(j, 0, boxes[i].size())
			ans += (i+1) * boxes[i][j].second * (j+1);
	cout << ans << '\n';
}

int main() {
	freopen("in.txt", "r", stdin);
	string in; getline(cin, in);
	part1(in);
	part2(in);
}