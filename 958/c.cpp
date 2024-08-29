#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void solve(long long n) {
    vector<long long> a;
    vector<int> num;
    long long m = n;

    a.push_back(n);
    while (n > 0) {
        num.push_back(n % 2);
        n = n / 2;
    }

    n = m;

    // series is reversed
    long long curr = 1;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == 1 and n > curr) a.push_back(n - curr);
        curr *= 2;
    }

    cout << a.size() << '\n';
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << '\n';
    return;
}

int main() {
    int test;
    cin >> test;
    long long n;
    for (int i = 0; i < test; i++){
        cin >> n;
        solve(n);
    }
    return 0;
}