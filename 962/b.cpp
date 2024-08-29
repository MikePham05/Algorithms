#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(int n, int k, vector<vector<char>>& a) {
    for (int i = 0; i < n; i = i + k) {
        for (int j = 0; j < n; j = j + k)
            cout << a[i][j];
        cout << endl;
    }
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n, k;
        cin >> n >> k;
        vector<vector<char>> a(n, vector<char>(n));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
                cin >> a[j][k];
        }
        solve(n, k, a);
    }
    return 0;
}