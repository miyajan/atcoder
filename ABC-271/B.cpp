#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<ll>> a(N + 1);
    for (int i = 1; i <= N; i++) {
        int L;
        cin >> L;
        for (int j = 1; j <= L; j++) {
            ll aa;
            cin >> aa;
            a.at(i).push_back(aa);
        }
    }

    for (int i = 0; i < Q; i++) {
        int s, t;
        cin >> s >> t;

        cout << a.at(s).at(t - 1) << endl;
    }
}
