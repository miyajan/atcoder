#include <bits/stdc++.h>

using namespace std;

long long N, M, X, T, D;

int main() {
    cin >> N >> M >> X >> T >> D;

    if (M <= X) {
        cout << T - D * (X - M) << endl;
    } else {
        cout << T << endl;
    }
}
