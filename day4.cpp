#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void part1() {
	long long ans = 0;
	INPUT(line) {
		stringstream ss(line);
		string token;
		ss >> token >> token >> token;
		
		set<int> winners;
		while (token != "|") {
			winners.insert(stoi(token));
			ss >> token;
		}

		int value = 1;
		while (ss >> token)
			if (winners.count(stoi(token)))
				value *= 2;
		ans += value/2;
	}
	cout << ans;
}

void part2() {
	long long ans = 0;
	long long cards[1000];
	memset(cards, 0, sizeof cards);
	INPUT(line) {
		stringstream ss(line);
		string token;

		ss >> token >> token;
		token.pop_back();
		int game = stoi(token);
		ans += ++cards[game];

		ss >> token;
		set<int> winners;
		while (token != "|") {
			winners.insert(stoi(token));
			ss >> token;
		}

		int matches = 0;
		while (ss >> token)
			if (winners.count(stoi(token)))
				++matches;

		while (matches > 0) {
			cards[game+matches] += cards[game];
			--matches;
		}
	}
	cout << ans;
}

void main() {
	part1();
	part2();
}