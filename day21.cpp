#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)

int a[5]{ 0, -1, 0, 1, 0 };
int main() {
    vector<string> grid;
    INPUT(line) grid.push_back(line);

    // only works on real input, not sample case
    int valid[2]{ 0, 0 };
    vector<int> y;
    queue<pair<int, int>> bfs;
    set<pair<int, int>> seen;
    bfs.emplace(65, 65);
    seen.emplace(65, 65);
    for (int step = 0; step <= 65 + 131*2; ++step) {
        int k = bfs.size();
        while (k--) {
            auto [r, c] = bfs.front(); bfs.pop();
            ++valid[step % 2];
            for (int i = 1; i < 5; ++i) {
                int _r = r+a[i], _c = c+a[i-1];
                if (grid[(_r + 131*300000) % 131][(_c + 131*300000) % 131] != '#' && !seen.count({ _r, _c }))
                    bfs.emplace(_r, _c), seen.emplace(_r, _c);
            }
        }
        if ((step - 65) % 131 == 0)
            y.push_back(valid[step % 2]);
        if (step == 64)
            cout << valid[step % 2] << '\n';

    }
    int a = (y[2] - (2 * y[1]) + y[0]) / 2;
    int b = y[1] - y[0] - a;
    int c = y[0];

    long long n = 26501300 / 131;
    cout << a*n*n + b*n + c << '\n';
}