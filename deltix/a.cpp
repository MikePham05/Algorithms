#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

const string endline = "\n";

void solve(vector<int>&a, vector<int>&b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cout << "Alice" << endl;
            return;
        }
    }
    cout << "Bob" << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(a,b);
    }
    return 0;
}