#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(int n, int x, int y) {
    vector<int> a(n);
    x--; y--;
    for (int i = y - 1; i > -1; i--) 
        if (i == y - 1) a[i] = -1;
        else a[i] = -a[i + 1];
    for (int i = y; i <= x; i++) a[i] = 1;
    for (int i = x + 1; i < n; i++) 
        if (i == x + 1) a[i] = -1;
        else a[i] = -a[i - 1];
    for (auto e: a)
        cout << e << " ";
    cout << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n, x, y;
        cin >> n >> x >> y;
        solve(n, x, y);
    }
    int s;
    cin >> s;
    return 0;
}