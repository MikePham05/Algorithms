#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(int n) {
    int ans = n / 4;
    if (n % 4 > 0) ans++;
    cout << ans << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}