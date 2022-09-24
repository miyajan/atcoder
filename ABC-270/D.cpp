#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> A.at(i);
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(2, 0));
    dp.at(1).at(0) = 1;
    dp.at(1).at(1) = 0;
    for (ll i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (A.at(j) > i) {
                continue;
            }
            if (dp.at(i).at(0) < A.at(j) + dp.at(i - A.at(j)).at(1)) {
                dp.at(i).at(0) = A.at(j) + dp.at(i - A.at(j)).at(1);
                dp.at(i).at(1) = dp.at(i - A.at(j)).at(0);
            }
        }
//        cout << "dp[" << i << "][0]: " << dp.at(i).at(0) << endl;
//        cout << "dp[" << i << "][1]: " << dp.at(i).at(1) << endl;
    }

    cout << dp.at(N).at(0) << endl;
}
