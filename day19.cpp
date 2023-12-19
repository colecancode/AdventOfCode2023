#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)
typedef pair<int, int> ii;

long long ans;
map<string, vector<string>> workflow;
string xmas("xmas");
void dfs(string name, vector<int> part) {
	if (name == "A") {
		for (int val : part)
			ans += val;
		return;
	}
	if (name == "R") return;

	for (string condition : workflow[name]) {
		int idx = xmas.find(condition[0]);
		int colon = condition.find(':');
		string next = condition.substr(colon+1);
		int num = stoi(condition.substr(2, colon-2));

		if (condition[1] == '>') {
			if (part[idx] > num) {
				dfs(next, part);
				return;
			}
		}
		else {
			if (part[idx] < num) {
				dfs(next, part);
				return;
			}
		}
	}
}

void dfs(string name, vector<ii> part) {
	if (name == "A") {
		long long add = 1;
		for (auto [l, r] : part)
			add *= r-l+1;
		ans += add;
		return;
	}
	if (name == "R") return;

	for (string condition : workflow[name]) {
		int idx = xmas.find(condition[0]);
		int colon = condition.find(':');
		string next = condition.substr(colon+1);
		int num = stoi(condition.substr(2, colon-2));

		if (condition[1] == '>') {
			if (part[idx].second <= num) continue;
			
			vector<ii> cpy = part;
			cpy[idx].first = max(cpy[idx].first, num+1);
			dfs(next, cpy);
			part[idx].second = num;
		}
		else {
			if (part[idx].first >= num) continue;

			vector<ii> cpy = part;
			cpy[idx].second = min(cpy[idx].second, num-1);
			dfs(next, cpy);
			part[idx].first = num;
		}
	}
}

void solve(int part) {
	workflow.clear();
	INPUT(line) {
		int n = line.size(), i = line.find('{');
		string name = line.substr(0, i);

		while (++i != n) {
			int j = line.find(',', i);
			if (j == -1) j = n-1;
			workflow[name].push_back(line.substr(i, j-i));
			i = j;
		}
		workflow[name].back() = "a>0:" + workflow[name].back();
	}

	vector<vector<int>> parts;
	INPUT(line) {
		parts.push_back({ 0, 0, 0, 0 });
		int i = 0;
		FOR(k, 0, 4) {
			int j = line.find(',', i += 3);
			if (j == -1) j = line.size()-1;
			parts.back()[k] = stoi(line.substr(i, j-i));
			i = j;
		}
	}

	ans = 0;
	if (part == 1)
		for (vector<int> part : parts)
			dfs("in", part);
	else
		dfs("in", { ii(1, 4000), ii(1, 4000), ii(1, 4000), ii(1, 4000) });

	cout << ans << '\n';
}

int main() {
	solve(1);
	solve(2);
}