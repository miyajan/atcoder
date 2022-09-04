#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<pair<int, int>, int> txa;
    for (int i = 0; i < N; i++) {
        int t, x, a;
        cin >> t >> x >> a;
        txa[{t, x}] = a;
    }

    vector<vector<long long>> dp(100001, vector<long long>(5));
    dp[0][0] = 0;
    dp[0][1] = -10000000000000000;
    dp[0][2] = -10000000000000000;
    dp[0][3] = -10000000000000000;
    dp[0][4] = -10000000000000000;
    for (int i = 1; i <= 100000; i++) {
        for (int j = 0; j < 5; j++) {
            int a = 0;
            if (txa.find({i, j}) != txa.end()) {
                a = txa.at({i, j});
            }
            if (j > 0) {
                dp[i][j] = dp[i - 1][j - 1] + a;
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a);
            if (j < 4) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + a);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, dp[100000][i]);
    }
    cout << ans << endl;
}
