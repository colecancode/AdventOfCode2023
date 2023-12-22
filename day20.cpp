#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

int main() {
	map<string, pair<char, vector<string>>> modules;
	string feeder;
	INPUT(line) {
		stringstream ss(line);
		string name; ss >> name;
		string next; ss >> next;
		if (name != "broadcaster") {
			char type = name[0];
			name.erase(name.begin());
			modules[name].first = type;
		}
		while (ss >> next) {
			if (next.back() == ',')
				next.pop_back();
			modules[name].second.push_back(next);
			if (next == "rx")
				feeder = name;
		}
	}

	
	set<string> waiting;
	map<string, bool> ff_state; // flip flop
	map<string, set<string>> c_state; // conjunction
	for (auto [name, _data] : modules) {
		for (string next : _data.second) {
			if (modules[next].first == '&')
				c_state[next].insert(name);
			if (next == feeder)
				waiting.insert(name);
		}
	}

	int low = 0, high = 0;
	long long cycle_lcm = 1;
	for (int t = 1;; ++t) {
		queue<tuple<string, string, bool>> bfs;
		bfs.push({ "broadcaster", "button", 0 });
		while (!bfs.empty()) {
			auto [name, parent, pulse] = bfs.front(); bfs.pop();
			pulse ? ++high : ++low;

			auto [type, adj] = modules[name];
			if (type == '%') {
				if (pulse) continue;
				pulse = ff_state[name] = !ff_state[name];
			}
			else if (type == '&') {
				if (pulse) c_state[name].erase(parent);
				else c_state[name].insert(parent);
				pulse = !c_state[name].empty();
			}

			if (pulse && waiting.count(name)) {
				waiting.erase(name);
				cycle_lcm = lcm(cycle_lcm, t);
				if (waiting.empty()) {
					cout << cycle_lcm << '\n';
					exit(0);
				}
			}

			for (string next : adj)
				bfs.push({ next, name, pulse });
		}

		if (t == 1000)
			cout << (long long)low * high << '\n';
	}
}