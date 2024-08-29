#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(vector<int>& a) {
    sort(a.begin(), a.end());
    int n = a.size(), cnt = 0;
    int i = n - 1, curr = a[i];

    while (i > -1) {
        if (a[i] == curr) cnt++;
        else {
            if (cnt % 2 == 1) {
                cout << "YES" << endl;
                return;
            }
            curr = a[i];
            cnt = 1;
        };
        i--;
    }

    if (cnt % 2 == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];
        solve(a);
    }
    return 0;
}