#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, L, R;
    cin >> N >> L >> R;

    vector<long long> A(N);
    vector<long long> cum(N);
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        sum += A.at(i);
        cum.at(i) = sum;
    }

    vector<long long> min_left(N + 1);
    vector<long long> min_right(N + 1);
    min_left.at(0) = 0;
    min_right.at(0) = 0;
    for (int i = 1; i <= N; i++) {
        min_left.at(i) = min(min_left.at(i - 1) + A.at(i - 1), i * L);
        min_right.at(i) = min(min_right.at(i - 1) + A.at(N - i), i * R);
    }

    long long ans = sum;
    for (int i = 0; i <= N; i++) {
        ans = min(ans, min_left.at(i) + min_right.at(N - i));
    }

    cout << ans << endl;
}
