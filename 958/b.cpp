#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(int n, string s) {
    int a = 0, b = 0;
    if (s[0] == '0') b++; else a++;
    for (int i = 1; i < n; i++)
        if (s[i] == '1') a++;
        else if (s[i-1] == '1') b++;
    string ans = (a > b ? "YES" : "NO");
    cout << ans << '\n';
    return;
}

int main() {
    int test;
    cin >> test;
    int n;
    string s;
    for (int i = 0; i < test; i++){
        cin >> n;
        cin >> s;
        solve(n, s);
    }
    return 0;
}