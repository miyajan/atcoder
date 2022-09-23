#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll A, B, C;
    cin >> A >> B >> C;

    ll base = gcd(gcd(A, B), C);
    ll ans = (A / base - 1) + (B / base - 1) + (C / base - 1);
    cout << ans << endl;
}
