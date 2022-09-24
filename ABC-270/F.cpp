#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> X(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> X.at(i);
    }

    vector<ll> Y(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> Y.at(i);
    }

    vector<int> A(M + 1);
    vector<int> B(M + 1);
    vector<ll> Z(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> A.at(i) >> B.at(i) >> Z.at(i);
    }

    ll ans = LONG_LONG_MAX;
    for (int i = 0; i < 4; i++) {
        vector<tuple<ll, int, int>> paths;
        atcoder::dsu dsu(N + 3);

        for (int j = 1; j <= M; j++) {
            paths.emplace_back(Z.at(j), A.at(j), B.at(j));
        }
        if ((i & 1) == 1) {
            for (int j = 1; j <= N; j++) {
                paths.emplace_back(X.at(j), j, N + 1);
            }
        }
        if ((i & 2) == 2) {
            for (int j = 1; j <= N; j++) {
                paths.emplace_back(Y.at(j), j, N + 2);
            }
        }
        std::sort(paths.begin(), paths.end());

        ll total = 0;
        for (auto [cost, a, b]: paths) {
            if (!dsu.same(a, b)) {
                total += cost;
                dsu.merge(a, b);
//                cout << "i: " << i << ", a: " << a << ", b: " << b << ", cost: " << cost << ", total: " << total
//                     << endl;
            }
        }

        if (dsu.size(1) < N) {
            total = LONG_LONG_MAX;
        }

        ans = min(ans, total);
    }

    cout << ans << endl;
}
