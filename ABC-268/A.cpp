#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    ll ans = 1;
    set<ll> exists;
    exists.insert(A);
    if (exists.find(B) == exists.end()) {
        ans++;
        exists.insert(B);
    }
    if (exists.find(C) == exists.end()) {
        ans++;
        exists.insert(C);
    }
    if (exists.find(D) == exists.end()) {
        ans++;
        exists.insert(D);
    }
    if (exists.find(E) == exists.end()) {
        ans++;
        exists.insert(E);
    }

    cout << ans << endl;
}
