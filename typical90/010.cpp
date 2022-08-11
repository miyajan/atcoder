#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> prefix_sum1(N + 1);
    vector<long long> prefix_sum2(N + 1);
    for (int i = 1; i <= N; i++) {
        int C, P;
        cin >> C >> P;
        prefix_sum1.at(i) = prefix_sum1.at(i - 1);
        prefix_sum2.at(i) = prefix_sum2.at(i - 1);
        if (C == 1) {
            prefix_sum1.at(i) += P;
        } else {
            prefix_sum2.at(i) += P;
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;

        cout << prefix_sum1.at(R) - prefix_sum1.at(L - 1) << " " << prefix_sum2.at(R) - prefix_sum2.at(L - 1) << endl;
    }
}
