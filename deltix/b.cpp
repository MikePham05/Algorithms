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
    int alice[2] = {a[0], a[n - 1]}, bob[2] = {b[0], b[n - 1]};
    int a1 = 0, a2 = n - 1, b1 = 0, b2 = n - 1;

    while (a1 < a2 - 1) {
        if (alice[0] == bob[0] and alice[1] == bob[1]) {
            a1++;
            b1++;
            alice[0] = a[a1];
            bob[0] = b[b1];
        } else if (alice[0] == bob[1] and alice[1] == bob[0]) {
            a1++;
            b2--;
            alice[0] = a[a1];
            bob[1] = b[b2];
        } else if (alice[1] == bob[0] and alice[0] == bob[1]) {
            a2--;
            b1++;
            alice[1] = a[a2];
            bob[0] = b[b1];
        } else if (alice[1] == bob[1] and alice[0] == bob[0]) {
            a2--;
            b2--;
            alice[1] = a[a2];
            bob[1] = b[b2];
        } else {
            cout << "Alice" << endl;
            return;
        }
    }

    int alice1[2] = {max(alice[0], alice[1]), min(alice[0], alice[1])};
    int bob1[2] = {max(bob[0], bob[1]), min(bob[0], bob[1])};

    if (alice1[0] != bob1[0] or alice1[1] != bob1[1])
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int i = 0; i < test; i++){
        int n;
        cin >> n;
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