#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> X(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> X.at(i);
    }

    unordered_map<int, long long> counterBonus;
    for (int i = 0; i < M; i++) {
        int c;
        long long y;
        cin >> c >> y;
        counterBonus[c] = y;
    }

    vector<long long> xPrefixSum(N + 1);
    xPrefixSum.at(0) = 0;
    vector<long long> bonusPrefixSum(N + 1);
    bonusPrefixSum.at(0) = 0;
    for (int i = 1; i <= N; i++) {
        xPrefixSum.at(i) = xPrefixSum.at(i - 1) + X.at(i);
        if (counterBonus.find(i) != counterBonus.end()) {
            bonusPrefixSum.at(i) = bonusPrefixSum.at(i - 1) + counterBonus.at(i);
            // cout << "bonuxPrefixSum.at(" << i << ") : " << bonusPrefixSum.at(i) << endl;
        } else {
            bonusPrefixSum.at(i) = bonusPrefixSum.at(i - 1);
        }
    }

    vector<long long> dp(N + 1);
    dp.at(0) = 0;
    for (int i = 1; i <= N; i++) {
        // cout << i << " round" << endl;
        dp.at(i) = dp.at(i - 1) + X.at(i);
        // cout << "ボーナスを考慮しない場合の max : " << dp.at(i) << endl;
        for (auto [c, y]: counterBonus) {
            if (i >= c) {
                long long preMax = i - c - 1 < 0 ? 0 : dp.at(i - c - 1);
                long long value = preMax;
                value += xPrefixSum.at(i) - xPrefixSum.at(i - c);
                value += bonusPrefixSum.at(c);
                // cout << i - c - 1 << "回で失敗して" << c << "連勝した場合の max : " << value << endl;
                if (value > dp.at(i)) {
                    dp.at(i) = value;
                }
            }
        }
    }
    cout << dp[N] << endl;
}
