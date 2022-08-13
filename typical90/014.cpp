#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < N; i++) {
        cin >> B.at(i);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(A.at(i) - B.at(i));
    }

    cout << ans << endl;
}
