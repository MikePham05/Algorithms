#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(int n, vector<long long> s) {
    int even = 0, odd = 0;
    for (auto c: s) {
        if (c % 2 == 0) even += 1;
        else odd += 1;
    }

    int ans = 0;
    if (odd == 0 or even == 0) ans = 0;
    else {
        sort(s.begin(), s.end());
        long long curr = 0;
        int i = n - 1;
        while (s[i] % 2 == 0) i--;
        for (int j = 0; j < i; j++) {
            if (s[j] % 2 == 0) {
                curr += s[j];
            }      
        }
        curr += s[i];
        for (int j = i + 1; j < n; j++) {
            if (curr < s[j]) {
                ans++;
                break;
            } else {
                curr += s[j];
            }
        }
        ans += even;
    }

    cout << ans << '\n';
    return;
}

int main() {
    int test;
    cin >> test;
    vector<long long> s;
    int n;
    for (int i = 0; i < test; i++){
        cin >> n;
        s = vector<long long>(n);
        for (int j = 0; j < n; j++)
            cin >> s[j];
        solve(n, s);
    }
    return 0;
}