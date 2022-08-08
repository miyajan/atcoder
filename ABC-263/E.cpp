#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 1; i <= N - 1; i++) {
        cin >> A.at(i);
    }

    vector<mint> dp(N + 1);
    dp.at(N) = 0;
    vector<mint> cum_dp(N + 2);
    cum_dp.at(N) = 0;
    cum_dp.at(N + 1) = 0;
    for (int i = N - 1; i >= 1; i--) {
        dp.at(i) = (mint(A.at(i)) + 1) / mint(A.at(i)) +
                   (cum_dp.at(i + 1) - cum_dp.at(i + A.at(i) + 1)) / mint(A.at(i));
        cum_dp.at(i) = cum_dp.at(i + 1) + dp.at(i);
    }
    cout << dp.at(1).val() << endl;
}
