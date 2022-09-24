#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs(ll N, ll X, ll Y, vector<vector<ll>> &paths, ll current, vector<ll> &current_paths, set<ll> &visited) {
    visited.insert(current);
    if (current == Y) {
        return true;
    }

    for (auto next: paths.at(current)) {
        if (visited.find(next) == visited.end()) {
            current_paths.push_back(next);
            bool result = dfs(N, X, Y, paths, next, current_paths, visited);
            if (result) {
                return result;
            }
            current_paths.pop_back();
        }
    }

    return false;
}

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<ll>> paths(N + 1);
    for (ll i = 0; i < N - 1; i++) {
        ll U, V;
        cin >> U >> V;
        paths.at(U).push_back(V);
        paths.at(V).push_back(U);
    }

    vector<ll> current_paths = {X};
    set<ll> visited;
    dfs(N, X, Y, paths, X, current_paths, visited);

    for (long unsigned int i = 0; i < current_paths.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << current_paths.at(i);
    }
    cout << endl;
}
