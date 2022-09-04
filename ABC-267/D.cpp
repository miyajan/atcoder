#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N + 1);
    for (long long i = 1; i <= N; i++) {
        cin >> A.at(i);
    }

    long long min = 0;
    for (long long i = 1; i <= 2000; i++) {
        min -= i * 2 * 100000;
    }
    // cout << min << endl;

    vector<vector<long long>> dp(N + 1, vector<long long>(M + 1));
    for (long long i = 1; i <= M; i++) {
        dp.at(0).at(i) = min;
    }

    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= M; j++) {
            dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i - 1).at(j - 1) + A.at(i) * j);
        }
    }

    cout << dp.at(N).at(M) << endl;
}
