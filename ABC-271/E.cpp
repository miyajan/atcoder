#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(M + 1);
    vector<int> B(M + 1);
    vector<ll> C(M + 1);
    for (int i = 1; i <= M; i++) {
        cin >> A.at(i) >> B.at(i) >> C.at(i);
    }

    vector<int> E(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> E.at(i);
    }

    map<int, ll> pos_min_cost;
    pos_min_cost[1] = 0;
    for (int i = 1; i <= K; i++) {
        if (pos_min_cost.find(A.at(E.at(i))) != pos_min_cost.end()) {
            if (pos_min_cost.find(B.at(E.at(i))) == pos_min_cost.end() ||
                pos_min_cost.at(A.at(E.at(i))) + C.at(E.at(i)) < pos_min_cost.at(B.at(E.at(i)))) {
                pos_min_cost[B.at(E.at(i))] = pos_min_cost.at(A.at(E.at(i))) + C.at(E.at(i));
            }
        }
    }

    if (pos_min_cost.find(N) == pos_min_cost.end()) {
        cout << -1 << endl;
    } else {
        cout << pos_min_cost.at(N) << endl;
    }
}
