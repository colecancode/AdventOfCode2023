#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void part1() {
	string directions;
	INPUT(line) directions = line;

	map<string, pair<string, string>> adj;
	INPUT(line)
		adj[line.substr(0, 3)] = { line.substr(7, 3), line.substr(12, 3) };

	int steps = 0, i = 0;
	string node = "AAA";
	for (; node != "ZZZ"; ++steps) {
		if (directions[i] == 'L') node = adj[node].first;
		else node = adj[node].second;
		i = (i+1) % directions.size();
	}
	cout << steps << '\n';
}

// this LCM solution shouldn't work... the problem restricts input without stating it
void part2() {
	string directions;
	INPUT(line) directions = line;

	map<string, pair<string, string>> adj;
	INPUT(line)
		adj[line.substr(0, 3)] = { line.substr(7, 3), line.substr(12, 3) };

	long long ans = 1;
	for (auto [u, v] : adj) {
		string node = u;
		if (node[2] != 'A') continue;
		int steps = 0, i = 0;
		for (; node[2] != 'Z'; ++steps) {
			if (directions[i] == 'L') node = adj[node].first;
			else node = adj[node].second;
			i = (i + 1) % directions.size();
		}
		ans = lcm(ans, steps);
	}
	cout << ans << '\n';
}

int main() {
	part1();
	part2();
}