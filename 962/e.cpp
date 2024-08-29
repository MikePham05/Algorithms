#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

void solve(string& s) {
    int n = s.size();
    vector<ll> prefix(n, 0);
    prefix[0] = (s[0] == '0') ? -1 : 1;
    for (int i = 1; i < n; i++) {
        char c = s[i];
        prefix[i] = prefix[i - 1];
        prefix[i] += (c == '0') ? -1 : 1;
    }

    map<int, vector<ll>> d;
    d.insert(pair<int, vector<ll>>(0, {}));
    d[0].push_back(-1);
    int p;
    for (int i = 0; i < n; i++) { 
        p = prefix[i];
        if (d.find(p) == d.end())
            d.insert(pair<int, vector<ll>>(p, {}));
        d[p].push_back(i);
    }
    
    // cal value
    ll mod = 1000000007;
    ll ans = 0;
    for (auto p: d) {
        int key = p.first;
        vector<ll> val = p.second;
        int ns = val.size();
        vector<ll> r(ns);
        r[0] = val[0] + 2;
        for (int i = 1; i < ns; i++)
            r[i] = r[i - 1] + val[i] + 2;
        for (int i = ns - 1; i > 0; i--)
            ans = (ans + ((n - val[i]) * r[i - 1]) % mod) % mod;
    }

    cout << ans << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}