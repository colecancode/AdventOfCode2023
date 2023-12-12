#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void part1() {
	map<string, int> cap{
		{"red", 12},
		{"green", 13},
		{"blue", 14}
	};
	int ans = 0;
	INPUT(line) {
		stringstream ss(line);
		string token;
		ss >> token >> token;

		token.pop_back();
		int game = stoi(token);

		bool flag = 1;
		while (ss >> token) {
			int n = stoi(token);
			ss >> token;
			if (!isalpha(token.back()))
				token.pop_back();

			flag &= n <= cap[token];
		}
		if (flag) ans += game;
	}
	cout << ans << '\n';
}

void part2() {
	int ans = 0;
	INPUT(line) {
		stringstream ss(line);
		string token;
		ss >> token >> token;

		map<string, int> floor;
		while (ss >> token) {
			int n = stoi(token);
			ss >> token;
			if (!isalpha(token.back()))
				token.pop_back();

			floor[token] = max(floor[token], n);
		}
		ans += floor["red"] * floor["green"] * floor["blue"];
	}
	cout << ans << '\n';
}

int main() {
	part1();
	part2();
}