#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int Q;
    cin >> Q;

    std::sort(A.begin(), A.end());

    for (int i = 0; i < Q; i++) {
        long long B;
        cin >> B;

        auto lb = std::lower_bound(A.begin(), A.end(), B);
        long long diff1 = abs(*lb - B);
        if (lb == A.begin()) {
            cout << diff1 << endl;
        } else {
            lb--;
            long long diff2 = abs(*lb - B);
            cout << min(diff1, diff2) << endl;
        }
    }
}
