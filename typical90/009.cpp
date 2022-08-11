#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> X(N + 1);
    vector<long long> Y(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }

    double ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<double> r;
        long long x1 = X.at(i);
        long long y1 = Y.at(i);
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                continue;
            }
            long long x2 = X.at(j);
            long long y2 = Y.at(j);
            r.push_back(atan2(y2 - y1, x2 - x1) * 180 / M_PI);
        }

        sort(r.begin(), r.end());
//        for (int j = 0; j < N - 1; j++) {
//            cout << "r[" << j << "]: " << r[j] << endl;
//        }

        for (int j = 0; j < N - 1; j++) {
            double r1 = r.at(j);
            double expected = r1 + 180;
            if (expected > 180) {
                expected -= 360;
            }
            auto it = lower_bound(r.begin(), r.end(), expected);
            if (it == r.end()) {
                it = r.begin();
            }
            double r2 = *it;
            double ma = min(abs(r1 - r2), 360 - abs(r1 - r2));
            // cout << "r1: " << r1 << ", r2: " << r2 << ", ma: " << ma << endl;
            if (it == r.begin()) {
                it = r.end() - 1;
            } else {
                it--;
            }
            r2 = *it;
            ma = max(ma, min(abs(r1 - r2), 360 - abs(r1 - r2)));
            // cout << "r1: " << r1 << ", r2: " << r2 << ", ma: " << ma << endl;
            if (ma > ans) {
                ans = ma;
            }
        }
    }

    cout << setprecision(12) << ans << endl;
}
