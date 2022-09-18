#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    vector<ll> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
    }

    vector<ll> scores(N, 0);
    for (int i = 0; i < N; i++) {
        ll j = p.at(i) - 1 - i;
        while (j < 0) {
            j += N;
        }
        scores.at(j % N)++;
        scores.at((j + 1) % N)++;
        scores.at((j + 2) % N)++;

//        cout << "p[" << i << "] = " << p.at(i) << endl;
//        for (int k = 0; k < N; k++) {
//            cout << "scores[" << k << "] = " << scores.at(k) << endl;
//        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(scores.at(i), ans);
    }

    cout << ans << endl;
}
