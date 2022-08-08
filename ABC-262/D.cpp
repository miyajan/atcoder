#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a.at(i);
    }

    vector<vector<vector<vector<long long>>>> dp(N + 1, vector<vector<
            vector<long long>>>(N + 1, vector<vector<long long>>(N + 1, vector<long long>(N + 1))));

    for (int i = 0; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][0][j][0] = 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= N; k++) {
                for (int l = 0; l < N; l++) {
                    long long mod = a.at(i) % k;
                    long long x = l - mod;
                    if (x < 0) {
                        x += k;
                    }
                    dp[i][j][k][l] += dp[i - 1][j - 1][k][x];
                    dp[i][j][k][l] %= 998244353;
                    dp[i][j][k][l] += dp[i - 1][j][k][l];
                    dp[i][j][k][l] %= 998244353;
                    // cout << "dp[" << i << "][" << j << "][" << k << "][" << l << "] = " << dp[i][j][k][l] << endl;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[N][i][i][0];
        ans %= 998244353;
    }
    cout << ans << endl;
}
