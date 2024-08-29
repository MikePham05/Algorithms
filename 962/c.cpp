#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

void solve(string& a, string& b, vector<vector<int>> &da, vector<vector<int>> &db, int l, int r) {
    int total = r - l + 1;

    // check b
    for (int i = 0; i < 30; i++) {
            int amountb, amounta;
            if (l == 0) amountb = db[i][r]; else amountb = db[i][r] - db[i][l-1];
            if (l == 0) amounta = da[i][r]; else amounta = da[i][r] - da[i][l-1];
            total -= min(amountb, amounta);
        }
    
    cout << total << endl;
    return;
}

int main() {
    int test;
    cin >> test;
    for (int te = 0; te < test; te++){
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a;
        cin >> b;
        // count hash
        vector<vector<int>> da(30, vector<int>(n, 0)), db(30, vector<int>(n, 0));

        for (int i = 0; i < 30; i++) {
            // a
            char c = static_cast<int>(i + 97);
            if (a[0] == c) da[i][0] = 1;
            // b
            if (b[0] == c) db[i][0] = 1;
            for (int j = 1; j < n; j++) {
                da[i][j] = da[i][j - 1];
                db[i][j] = db[i][j - 1];
                if (a[j] == c) da[i][j]++;
                if (b[j] == c) db[i][j]++;
            }

        }

        //
        int l, r;
        for (int j = 0; j < q; j++) {
            cin >> l >> r;
            solve(a, b, da, db, l - 1, r - 1);
        }
    }
    return 0;
}