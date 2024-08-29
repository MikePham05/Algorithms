#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(vector<long long>& x, vector<long long>&y, ll xs, ll ys, ll xt, ll yt) {
    int n = x.size();
    ll df = abs(xs - xt)*abs(xs - xt) + abs(ys - yt)*abs(ys - yt);
    vector<ll> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = abs(x[i] - xt)*abs(x[i] - xt) + abs(y[i] - yt)*abs(y[i] - yt);
        if (d[i] <= df) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n;
        cin >> n;
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        int xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;
        solve(x, y, xs, ys, xt, yt);
    }
    return 0;
}