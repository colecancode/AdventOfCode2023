#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)
#define ll long long
#define ii pair<ll, ll>

void part1() {
	ll ans = 0;
	vector<ll> seeds;
	INPUT(line) {
		stringstream ss(line);
		string tmp; ss >> tmp;
		
		ll seed;
		while (ss >> seed)
			seeds.push_back(seed);
	}

	for (int i = 0; i < 7; ++i) {
		string tmp; getline(cin, tmp);
		vector<ll> nxt;
		INPUT(line) {
			stringstream ss(line);
			ll d, s, rng;
			ss >> d >> s >> rng;

			for (ll& seed : seeds) {
				if (seed >= s && seed < s + rng) {
					nxt.push_back(d + (seed - s));
					seed = -1;
				}
			}
		}
		for (ll seed : seeds)
			if (seed != -1)
				nxt.push_back(seed);

		seeds = vector<ll>(begin(nxt), end(nxt));
		nxt.clear();
	}
	cout << *min_element(begin(seeds), end(seeds)) << '\n';
}

void part2() {
	vector<ii> seeds;
	INPUT(line) {
		stringstream ss(line);
		string tmp; ss >> tmp;

		ll start;
		while (ss >> start) {
			ll rng; ss >> rng;
			seeds.push_back({ start, start+rng-1 });
		}
	}

	for (int i = 0; i < 7; ++i) {
		string tmp; getline(cin, tmp);
		vector<ii> nxt;
		INPUT(line) {
			stringstream ss(line);
			ll d, s, rng;
			ss >> d >> s >> rng;

			// extra ranges when one splits into two
			vector<ii> q;
			for (auto& [l, r] :seeds) {
				if (l == -1) continue;
				ll sEnd = s + rng - 1;
				// not in range
				if (r < s || l > sEnd) continue;
				if (l <= s && r >= sEnd) {
					// fully encompasses range
					nxt.push_back({ d, d + rng });
					if (sEnd < r)
						q.push_back({ sEnd + 1, r });
					if (l < s)
						r = s - 1;
					else
						l = -1;
					break;
				}

				// partial overlap
				ll L = max(l, s), R = min(r, sEnd);
				nxt.push_back({ d+L-s, d+R-s });
				if (l < L)
					r = L - 1;
				else if (r > R)
					l = R + 1;
				else
					l = -1;
			}
			for (ii rng : q)
				seeds.push_back(rng);
		}
		// build resulting set of ranges
		for (auto& [l, r] : seeds)
			if (l != -1)
				nxt.push_back({ l, r });

		seeds = vector<ii>(begin(nxt), end(nxt));
		nxt.clear();
	}
	cout << min_element(begin(seeds), end(seeds))->first << '\n';
}

void main() {
	part1();
	part2();
}