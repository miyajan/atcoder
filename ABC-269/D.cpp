#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using ll = long long;

int to_index(int X, int Y) {
    return (X + 1000) * 1001 + (Y + 1000);
}

int main() {
    ll N;
    cin >> N;

    atcoder::dsu d(2001 * 2001);
    vector<int> X(N + 1);
    vector<int> Y(N + 1);
    vector<vector<bool>> maths(2002, vector<bool>(2002));
    for (int i = 1; i <= N; i++) {
        cin >> X.at(i) >> Y.at(i);
        maths.at(X.at(i) + 1000).at(Y.at(i) + 1000) = true;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if ((j == -1 && k == 1) || (j == 0 && k == 0) || (j == 1 && k == -1) || X.at(i) + j < -1000 ||
                    X.at(i) + j > 1000 ||
                    Y.at(i) + k < -1000 || Y.at(i) + k > 1000) {
                    continue;
                }
                if (maths.at(X.at(i) + 1000 + j).at(Y.at(i) + 1000 + k)) {
                    d.merge(to_index(X.at(i), Y.at(i)), to_index(X.at(i) + j, Y.at(i) + k));
                }
            }
        }
    }

    ll ans = 0;
    set<int> leaders;
    for (int i = 1; i <= N; i++) {
        int index = to_index(X.at(i), Y.at(i));
        int leader = d.leader(index);
        if (leaders.find(leader) == leaders.end()) {
            ans++;
            leaders.insert(leader);
        }
    }

    cout << ans << endl;
}
