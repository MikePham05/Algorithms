#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(int n, int k) {
    if (n == 1) {
        cout << 0 << '\n';
        return;
    } else if (k == 2) {
        cout << n - 1 << '\n';
        return;
    }

    int ans = n / (k - 1);
    if (n % (k - 1) > 1) ans++;
    cout << ans << '\n';
    return;
}

int main() {
    int test;
    cin >> test;
    int n, k;
    string s;
    for (int i = 0; i < test; i++){
        cin >> n;
        cin >> s;
        solve(n, s);
    }
    return 0;
}