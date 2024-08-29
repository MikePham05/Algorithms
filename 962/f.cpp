#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

struct val {
    int va;
    int vb;

    val(int a, int b) : va(a), vb(b){}};

int getcnt(val v) {
    ll cnt = v.va / v.vb;
    cnt += (v.va % v.vb == 0) ? 0 : 1;
    return cnt;
}

bool compare(val a, val b) {
    return a.va * getcnt(a) > b.va * getcnt(b);
}

void solve(vector<int>& a, vector<int>& b, int k) {
    int n = a.size();
    vector<val> d(n, val(0, 0));
    for (int i = 0; i < n; i++) {
        d[i].va = a[i];
        d[i].vb = b[i];
    }

    sort(d.begin(), d.end(), compare);
    int i = 0;
    ll ans = 0;
    while (k > 0 and i < n) {
        ll cnt = d[i].va / d[i].vb;
        cnt += (d[i].va % d[i].vb == 0) ? 0 : 1;
        cnt = min((ll) k, cnt);
        k -= cnt;
        ans += cnt * d[i].va; 
    }
    cout << ans << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n , k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        for (int j = 0; j < n; j++)
            cin >> b[j];
        solve(a, b, k);
    }
    return 0;
}