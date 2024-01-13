#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            a[i][j] = ch == '*';
        }
    }

    vector<vector<int>> bit(n + 1, vector<int>(n + 1));
    
    auto add = [&] (int r, int c, int val) {
        for (++r; r <= n; r += r & -r) {
            for (int j = c + 1; j <= n; j += j & -j) {
                bit[r][j] += val;
            }
        }
    };

    auto sum = [&] (int r, int c) {
        int res = 0;
        for (++r; r > 0; r -= r & -r) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                res += bit[r][j];
            }
        }
        return res;
    };

    auto getMatrixSum = [&] (int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            add(i, j, a[i][j]);
        }
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int row, col;
            cin >> row >> col;
            row--, col--;

            add(row, col, 1 - 2 * a[row][col]);
            a[row][col] ^= 1;
        }

        else {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--, c1--, r2--, c2--;

            cout << getMatrixSum(r1, c1, r2, c2) << endl;
        }
    }
    
    return 0;
}
