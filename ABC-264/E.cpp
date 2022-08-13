#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;

int main() {
    int N, M, E;
    cin >> N >> M >> E;

    vector<int> U(E + 1);
    vector<int> V(E + 1);
    for (int i = 1; i <= E; i++) {
        cin >> U.at(i) >> V.at(i);
    }

    int Q;
    cin >> Q;
    vector<int> X(Q + 1);
    unordered_map<int, bool> X_exists;
    for (int i = 1; i <= Q; i++) {
        cin >> X.at(i);
        X_exists[X.at(i)] = true;
    }

    atcoder::dsu dsu(N + M + 1);
    for (int i = N + 1; i < N + M; i++) {
        dsu.merge(i, N + M);
    }

    for (int i = 1; i <= E; i++) {
        if (X_exists.count(i) == 0) {
            // cout << "i: " << i << endl;
            dsu.merge(U.at(i), V.at(i));
        }
    }

    vector<int> ans(Q + 1);
    ans.at(Q) = dsu.size(N + M) - M;
    // cout << "ans.at(Q): " << ans.at(Q) << endl;
    for (int i = Q; i > 1; i--) {
        dsu.merge(U.at(X.at(i)), V.at(X.at(i)));
        ans.at(i - 1) = dsu.size(N + M) - M;
    }

    for (int i = 1; i <= Q; i++) {
        cout << ans.at(i) << endl;
    }
}
