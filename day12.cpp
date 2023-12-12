#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void solve(int part) {
	long long ans = 0;
	INPUT(line) {
		int space = line.find(' ');
		string info = line.substr(0, space);
		string lengths = line.substr(space+1);

		// scuffed IO
		vector<int> arr;
		int x = 0;
		while (1) {
			int y = lengths.find(',', x);
			if (y == -1) break;
			arr.push_back(stoi(lengths.substr(x, y-x)));
			x = y+1;
		}
		arr.push_back(stoi(lengths.substr(x)));

		if (part == 2) {
			string info_cpy = info;
			FOR(i, 1, 5) info += "?" + info_cpy;
			vector<int> arr_cpy = arr;
			FOR(i, 1, 5) arr.insert(arr.end(), arr_cpy.begin(), arr_cpy.end());
		}
		info.push_back('.');

		int n = info.size(), m = arr.size();
		info.insert(begin(info), ' ');	// one based
		arr.insert(begin(arr), 0);		// indexing
		vector<vector<long long>> dp(n+1, vector<long long>(m+1));
		dp[0][0] = 1;
		FOR(i, 1, n+1) {
			FOR(j, 0, m+1) {
				if (info[i] != '#')
					dp[i][j] += dp[i - 1][j];

				if (j > 0 && info[i] != '.') {
					if (i+arr[j] > n || info.substr(i, arr[j]).find('.') != -1 || info[i+arr[j]] == '#') continue; // try to construct section
					dp[i+arr[j]][j] += dp[i-1][j-1];
				}
			}
		}
		ans += dp[n][m];
	}
	cout << ans << '\n';
}

int main() {
	solve(1);
	solve(2);
}