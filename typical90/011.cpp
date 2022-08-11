#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<pair<int, pair<int, long long>>> tasks;
    for (int i = 0; i < N; i++) {
        int D, C;
        long long S;
        cin >> D >> C >> S;
        tasks.push_back({D, {C, S}});
    }

    sort(tasks.begin(), tasks.end());

    vector<vector<long long>> dp(N + 1, vector<long long>(5001));
    for (int i = 1; i <= N; i++) {
        int D = tasks.at(i - 1).first;
        int C = tasks.at(i - 1).second.first;
        long long S = tasks.at(i - 1).second.second;
        // cout << "D: " << D << ", C: " << C << ", S: " << S << endl;
        for (int j = 1; j <= 5000; j++) {
            if (j < C) {
                dp.at(i).at(j) = dp.at(i - 1).at(j);
            } else if (D < j) {
                dp.at(i).at(j) = dp.at(i).at(j - 1);
            } else {
                dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i - 1).at(j - C) + S);
            }
            // cout << "dp[" << i << "][" << j << "]: " << dp.at(i).at(j) << endl;
        }
    }
    cout << dp.at(N).at(5000) << endl;
}
