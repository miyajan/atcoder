#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A.at(i);
    }

    vector<set<long long>> conns(N + 1);
    vector<long long> costs(N + 1, 0);
    for (int i = 0; i < M; i++) {
        long long U, V;
        cin >> U >> V;
        conns.at(U).insert(V);
        conns.at(V).insert(U);
        costs.at(U) += A.at(V);
        costs.at(V) += A.at(U);
    }

    set<pair<long long, long long>> points;
    for (int i = 1; i <= N; i++) {
        points.insert({costs.at(i), i});
    }

    long long ans = 0;
    while (!points.empty()) {
        pair<long long, long long> point = *points.begin();
        ans = max(ans, point.first);
        for (auto p: conns.at(point.second)) {
            points.erase({costs.at(p), p});
            conns.at(p).erase(point.second);
            costs.at(p) -= A.at(point.second);
            points.insert({costs.at(p), p});
        }
        points.erase(point);
    }

    cout << ans << endl;
}
