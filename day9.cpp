#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

void solve(int part) {
	long long ans = 0;
	INPUT(line) {
		stringstream ss(line);
		vector<vector<int>> arr(1);
		int x;
		while (ss >> x)
			arr[0].push_back(x);

		for (int i = 0;; ++i) {
			arr.push_back({});
			bool flag = 1;
			FOR(j, 1, arr[i].size()) {
				flag &= arr[i][j] == arr[i][j-1];
				arr[i+1].push_back(arr[i][j] - arr[i][j-1]);
			}
			if (flag) break;
		}

		for (int i = arr.size()-1; i > 0; --i) {
			if (part == 1)
				arr[i-1].push_back(arr[i].back() + arr[i-1].back());
			else
				arr[i-1].push_back(*begin(arr[i-1]) - arr[i].back());
		}
		ans += arr[0].back();
	}
	cout << ans << '\n';
}

void main() {
	solve(1);
	solve(2);
}