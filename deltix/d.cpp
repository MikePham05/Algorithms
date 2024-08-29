#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(int q, vector<int>& parent, vector<int>& value) {
    // solve and build some data structures


    int v1, v2;
    for (int i = 0; i < q; i++) {
        cin >> v1 >> v2; // read queries
        // solve for query ith
    }
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n, q;
        cin >> n >> q;
        vector<int> parent(n), value(n);
        for (int i = 0; i < n; i++) cin >> parent[i];
        for (int i = 0; i < n; i++) cin >> value[i];
        solve(q, parent, value);
    }
    return 0;
}