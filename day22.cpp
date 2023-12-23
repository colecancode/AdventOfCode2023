#include <bits/stdc++.h>
using namespace std;
#define INPUT(var) for(string var; getline(cin, var), var!="";)
#define FOR(i, s, e) for (int i=s; i<e; ++i)
typedef tuple<int, int, int> point;

int main() {
    vector<pair<point, point>> bricks;
    INPUT(line) {
        for (char& c : line)
            if (!isdigit(c))
                c = ' ';
        bricks.push_back({ point(), point() });
        auto& [z1, x1, y1] = bricks.back().first;
        auto& [z2, x2, y2] = bricks.back().second;
        stringstream ss(line);
        ss >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    }
    sort(bricks.begin(), bricks.end());

    int n = bricks.size();
    map<point, int> seen;
    vector<set<int>> supporting(n), supported(n);
    FOR(i, 0, n) {
        auto [z1, x1, y1] = bricks[i].first;
        auto [z2, x2, y2] = bricks[i].second;

        int offset;
        for (offset = 1; min(z1, z2) - offset > 0;) {
            FOR(x, min(x1, x2), max(x1, x2) + 1) {
                FOR(y, min(y1, y2), max(y1, y2) + 1) {
                    int z = min(z1, z2) - offset;
                    if (seen.count({ x, y, z }))
                        supported[i].insert(seen[{ x, y, z }]);
                }
            }
            if (!supported[i].empty()) break;
            ++offset;
        }
        --offset;

        for (int j : supported[i])
            supporting[j].insert(i);

        FOR(x, min(x1, x2), max(x1, x2) + 1)
            FOR(y, min(y1, y2), max(y1, y2) + 1)
                FOR(z, min(z1, z2), max(z1, z2) + 1)
                    seen[{x, y, z - offset}] = i;
    }

    int part1 = 0, part2 = 0;
    FOR(i, 0, n) {
        bool critical = false;
        for (int j : supporting[i])
            if (supported[j].size() == 1)
                critical = true;
        if (!critical) ++part1;

        set<int> a{ i };
        while (true) {
            bool progress = false;
            set<int> add;
            for (int l : a) {
                for (int j : supporting[l]) {
                    if (a.count(j)) continue;
                    bool flag = true;
                    for (int k : supported[j])
                        flag &= a.count(k);

                    if (flag) {
                        progress = true;
                        add.insert(j);
                    }
                }
            }
            if (!progress) break;
            a.insert(add.begin(), add.end());
        }
        part2 += a.size() - 1;
    }

    cout << part1 << '\n';
    cout << part2 << '\n';
}
