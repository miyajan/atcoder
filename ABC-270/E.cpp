#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    vector<ll> A(N + 1);
    vector<ll> sorted_A(N + 1);
    for (ll i = 1; i <= N; i++) {
        cin >> A.at(i);
        sorted_A.at(i) = A.at(i);
    }
    std::sort(sorted_A.begin(), sorted_A.end());

    ll previous = 0;
    ll loop = 0;
    ll count = 0;
    ll remainder;
    for (ll i = 1; i <= N; i++) {
        ll x = sorted_A.at(i) - previous;
        if (count + ((N + 1) - i) * x > K) {
            loop += (K - count) / ((N + 1) - i);
            remainder = (K - count) % ((N + 1) - i);
            break;
        } else {
            loop += x;
            count += ((N + 1) - i) * x;
        }
        previous = sorted_A.at(i);
//        cout << "i: " << i << ", loop: " << loop << ", count: " << count;
    }
//    cout << "loop: " << loop << endl;
//    cout << "remainder: " << remainder << endl;

    for (ll i = 1; i <= N; i++) {
        if (i != 1) {
            cout << " ";
        }
//        cout << i << ":" << A.at(i) << ":";

        if (A.at(i) > loop) {
            ll ans = A.at(i) - loop;
            if (remainder > 0) {
                ans--;
                remainder--;
            }
            cout << ans;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}
