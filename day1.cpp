#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void part1() {
	int ans = 0;
	INPUT(line) {
		int first = 0, last = 0;
		for (char& c : line) {
			if (isdigit(c)) {
				if (!first)
					first = c - '0';
				last = c - '0';
			}
		}
		ans += first * 10 + last;
	}
	cout << ans;
}

void part2() {
	int ans = 0;
	string numbers[]{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	INPUT(line) {
		int first = 0, last = 0;
		FOR(i, 0, size(line)) {
			int digit = 0;
			if (isdigit(line[i]))
				digit = line[i] - '0';
			else {
				FOR(j, 1, 10)
					if (line.substr(i, numbers[j].size()) == numbers[j])
						digit = j;
			}

			if (digit) {
				if (!first)
					first = digit;
				last = digit;
			}
		}
		ans += first * 10 + last;
	}
	cout << ans;
}

int main() {
	part1();
	//part2();
}