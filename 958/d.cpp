#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(int n, vector<int>& c) {
    // build a
    sort(c.begin(), c.end());
    int curr = c[0], count = 0;
    vector<int> a;
    a.push_back(0);
    for (auto e: c)
        if (e == curr) {
            count += 1;
        } else { // new number
            a.push_back(count);
            count = 1;
            curr = e;
        }
    a.push_back(count);

    int ans = 50000000, oo = 5000000;
    vector<vector<int>> d(n + 2, vector<int>(n + 2, oo));
    d[1][1] = 0;
    for (int i = 2; i < a.size(); i++)
        for (int j = 0; j <= i; j++) {
            if (j + a[i] < a.size()) d[i][j] = max(d[i][j], d[i - 1][j + a[i]]);
            if (j > 0) d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
        }

    for (auto e: d[a.size() - 1])
        if (e > 0) ans = min(ans, e);

    cout << ans << '\n';
    return;
}

int main() {
    int test;
    cin >> test;
    int n;
    vector<int> a;
    for (int i = 0; i < test; i++){
        cin >> n;
        a = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        solve(n, a);
    }
    return 0;
}