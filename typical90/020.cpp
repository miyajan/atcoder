#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll blogc_pow = 1;
    for (int i = 1; i <= b; i++) {
        blogc_pow *= c;
    }
    if (a < blogc_pow) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
