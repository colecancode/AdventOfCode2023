#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

int score(string hand, int part) {
	map<char, int> f;
	int big = 0, j_cnt = 0;
	for (char c : hand) {
		if (c == 'J' && part == 2) ++j_cnt;
		else big = max(big, ++f[c]);
	}
	int types = f.size();
	if (part == 2) {
		if (j_cnt == 5)
			types = 1;
		big += j_cnt;
	}

	int sum;
	if (types == 1) sum = 6; // AAAAA
	else if (types == 2 && big == 4) sum = 5; // AAAAB
	else if (types == 2) sum = 4; // AAABB
	else if (types == 3 && big == 3) sum = 3; // AAABC
	else if (types == 3) sum = 2; // AABBC
	else if (types == 4) sum = 1; // AABCD
	else sum = 0; //ABCDE

	string precedence(part == 1 ? "23456789TJQKA" : "J23456789TQKA");
	for (char c : hand)
		sum = sum*13 + precedence.find(c);
	return sum;
}

void solve(int part) {
	vector<pair<int, int>> hands;
	INPUT(line) {
		stringstream ss(line);
		string hand; ss >> hand;
		int bid; ss >> bid;
		hands.push_back({ score(hand, part), bid });
	}
	sort(hands.begin(), hands.end());
	int ans = 0;
	FOR(rnk, 1, hands.size()+1)
		ans += rnk * hands[rnk-1].second;
	cout << ans << '\n';
}

int main() {
	solve(1);
	solve(2);
}