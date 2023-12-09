#include <bits/stdc++.h>
using namespace std;

void part1() {
	vector<int> time, best;
	string line; getline(cin, line);
	stringstream ss(line);
	string tmp; ss >> tmp;
	for (int t; ss >> t;)
		time.push_back(t);

	getline(cin, line);
	ss = stringstream(line);
	ss >> tmp;
	for (int b; ss >> b;)
		best.push_back(b);

	int ans = 1;
	for (int i = 0; i < time.size(); ++i) {
		double discriminant = sqrt(time[i] * time[i] - 4 * best[i]);
		int high = ceil((time[i] + discriminant) / 2) - 1;
		int low = floor((time[i] - discriminant) / 2) + 1;
		ans *= high - low + 1;
	}
	cout << ans << '\n';
}

void part2() {
	string line; getline(cin, line);
	stringstream ss(line);
	string tmp, time, best; ss >> tmp;
	for (string t; ss >> t;)
		time += t;

	getline(cin, line);
	ss = stringstream(line);
	ss >> tmp;
	for (string b; ss >> b;)
		best += b;

	long long t = stoll(time), b = stoll(best);
	double discriminant = sqrt(t*t - 4*b);
	int high = ceil((t + discriminant) / 2) - 1;
	int low = floor((t - discriminant) / 2) + 1;
	cout << high - low + 1 << '\n';
}

int main() {
	part1();
	part2();
}