#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

mint calc_row(ll N, ll M, ll i, ll j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    if (i % 2 == 1) {
        mint start = M * (i - 1) + 1;
        mint end = j % 2 == 0 ? M * (i - 1) + (j - 1) : M * (i - 1) + j;
        mint value_count = j % 2 == 0 ? j / 2 : j / 2 + 1;
        mint total = value_count == 1 ? start : ((end + start) / 2) * value_count;
//        cout << "i: " << i << ", j: " << j << ", start: " << start.val() << ", end: " << end.val()
//             << ", value_count: "
//             << value_count.val() << ", total: " << total.val() << endl;
        return total;
    } else {
        if (j == 1) {
            return 0;
        }
        mint start = M * (i - 1) + 2;
        mint end = j % 2 == 0 ? M * (i - 1) + j : M * (i - 1) + j - 1;
        mint value_count = j / 2;
        mint total = value_count == 1 ? start : ((end + start) / 2) * value_count;
//        cout << "i: " << i << ", j: " << j << ", start: " << start.val() << ", end: " << end.val()
//             << ", value_count: "
//             << value_count.val() << ", total: " << total.val() << endl;
        return total;
    }
}

mint calc_area(ll N, ll M, ll i, ll j) {
    if (i == 0 || j == 0) {
        return 0;
    }

    mint total_1 = calc_row(N, M, 1, j);
//    cout << "total_1: " << total_1.val() << endl;
    if (i == 1) {
        return total_1;
    }

    mint total_2 = calc_row(N, M, 2, j);
    if (i == 2) {
        return total_1 + total_2;
    }

    mint total_i = calc_row(N, M, i, j);
    if (i == 3) {
        return total_1 + total_2 + total_i;
    }

    mint total_i_minus_1 = calc_row(N, M, i - 1, j);

    mint odd_row_count = i % 2 == 0 ? i / 2 : i / 2 + 1;
    mint even_row_count = i / 2;

    if (i % 2 == 0) {
        return (total_1 + total_i_minus_1) / 2 * odd_row_count + (total_2 + total_i) / 2 * even_row_count;
    } else {
        return (total_1 + total_i) / 2 * odd_row_count + (total_2 + total_i_minus_1) / 2 * even_row_count;
    }
}

int main() {
    ll N, M;
    cin >> N >> M;

    ll Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;

        cout << (calc_area(N, M, B, D) - calc_area(N, M, B, C - 1) - calc_area(N, M, A - 1, D) +
                 calc_area(N, M, A - 1, C - 1)).val() << endl;
    }
}
