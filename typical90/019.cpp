#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    vector<ll> A(2 * N + 1);
    for (int i = 1; i <= 2 * N; i++) {
        cin >> A.at(i);
    }

    vector<vector<ll>> dp(2 * N + 1, vector<ll>(2 * N + 1, 0));
    for (int i = 1; i <= 2 * N - 1; i++) {
        dp.at(i).at(i + 1) = abs(A.at(i) - A.at(i + 1));
    }

    for (int i = 3; i <= 2 * N - 1; i += 2) {
        for (int j = 1; j <= 2 * N - i; j++) {
            int k = j + i;
            ll cost = dp.at(j).at(k - 2) + abs(A.at(k - 1) - A.at(k));
            for (int l = k - 2; l >= j + 1; l -= 2) {
                for (int m = l - 1; m >= j; m -= 2) {
                    cost = min(cost, dp.at(j).at(m - 1) + abs(A.at(m) - A.at(k)) + dp.at(m + 1).at(l - 1) +
                                     abs(A.at(l) - A.at(k - 1)) + dp.at(l + 1).at(k - 2));
                }
            }
            dp.at(j).at(k) = cost;
        }
    }

    cout << dp.at(1).at(2 * N) << endl;
}
