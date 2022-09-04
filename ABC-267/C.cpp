#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N + 1);
    for (long long i = 1; i <= N; i++) {
        cin >> A.at(i);
    }

    vector<long long> prefix_sum(N + 1);
    for (long long i = 0; i <= N; i++) {
        if (i == 0) {
            prefix_sum.at(i) = 0;
        } else {
            prefix_sum.at(i) = prefix_sum.at(i - 1) + A.at(i);
        }
        // cout << "prefix_sum[" << i << "] = " << prefix_sum[i] << endl;
    }

    long long ans = LLONG_MIN;
    long long prev;
    for (long long i = 1; i <= N - M + 1; i++) {
        long long val = 0;
        if (i == 1) {
            for (long long j = 1; j <= M; j++) {
                val = j * A.at(j) + val;
            }
        } else {
            val = prev;
            val -= prefix_sum.at(i + M - 2) - prefix_sum.at(i - 2);
            val += A.at(i + M - 1) * M;
        }
        if (ans < val) {
            ans = val;
        }
        prev = val;
        // cout << "val = " << val << endl;
    }

    cout << ans << endl;
}
