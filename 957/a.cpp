#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(int n, vector<int>& a) {
    int k = a.size();
    sort(a.begin(), a.end());
    int cnt1 = 0, other = 0;
    for (auto e: a)
        if (e == 1) cnt1++;
        else other += e;

    other -= a.back();
    int ans = 0;
    ans = other + other - (k - cnt1 - 1) + cnt1;

    cout << ans << '\n';

    return;
}

int main() {
    int test;
    cin >> test;
    int n, k;
    vector<int> a;
    for (int i = 0; i < test; i++){
        cin >> n >> k;
        a = vector<int>(k);
        for (int j = 0; j < k; j++)
            cin >> a[j];
        solve(n, a);
    }
    return 0;
}