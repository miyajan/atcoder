#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void first_dfs(ll node, vector<vector<ll>> &paths, stack<ll> &ordered_nodes, vector<bool> &visited) {
    visited.at(node) = true;
    for (auto next: paths.at(node)) {
        if (!visited.at(next)) {
            first_dfs(next, paths, ordered_nodes, visited);
        }
    }
    ordered_nodes.push(node);
}

void second_dfs(ll node, vector<vector<ll>> &paths, vector<bool> &visited, vector<ll> &scc) {
    visited.at(node) = true;
    scc.push_back(node);
    for (auto next: paths.at(node)) {
        if (!visited.at(next)) {
            second_dfs(next, paths, visited, scc);
        }
    }
}

int main() {
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> paths(N + 1);
    vector<vector<ll>> reverse_paths(N + 1);
    for (int i = 0; i < M; i++) {
        ll A, B;
        cin >> A >> B;
        paths.at(A).push_back(B);
        reverse_paths.at(B).push_back(A);
    }

    stack<ll> ordered_nodes;
    vector<bool> first_visited(N + 1);
    for (int i = 1; i <= N; i++) {
        if (!first_visited.at(i)) {
            first_dfs(i, paths, ordered_nodes, first_visited);
        }
    }

    unsigned long long ans = 0;
    vector<bool> second_visited(N + 1);
    while (!ordered_nodes.empty()) {
        ll node = ordered_nodes.top();
        ordered_nodes.pop();
        if (!second_visited.at(node)) {
            vector<ll> scc;
            second_dfs(node, reverse_paths, second_visited, scc);
            auto size = scc.size();
            ans += (size * (size - 1)) / 2;
        }
    }

    cout << ans << endl;
}
