#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(int n, int k, vector<int>& a) {
    int ans = -1;
    vector<int> r(k * 2, 0);
    for (auto c: a) {
        int p = c % k + ((c / k) % 2) * k;
        r[p] = c;
    }
    
    int m = *max_element(a.begin(), a.end());
    r[m%k+(m/k)%2*k] = m;
    int index_m;
    vector<int> b;
    for (int i = 0; i < k * 2; i++) 
        if (r[i] > 0) {
            b.push_back(i);
            if (r[i] == m) index_m = b.size() - 1;
        }

    for (int i = 1; i < b.size(); i++)
        if (b[i] - b[i - 1] > k) { // first = i, last = i - 1
            ans = m + (2 * k + b[i - 1] - b[index_m]) % k;
            cout << ans << '\n';
            return;
        }
    
    /*
        0: n - 1
        1: 0
        2: 1
    */
   // first = 0, last = n - 1
    if (2 * k + b[0] - b[b.size() - 1] > k) {
        ans = m + (2 * k + b[b.size() - 1] - b[index_m]) % k;
    } else ans = -1;
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
        a = vector<int>(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        solve(n, k, a);
    }
    return 0;
}