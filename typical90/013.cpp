#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, deque<int>> connected;
    unordered_map<int, unordered_map<int, int>> costs;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        if (connected.count(A) == 0) {
            connected[A] = {};
        }
        connected.at(A).push_back(B);

        if (connected.count(B) == 0) {
            connected[B] = {};
        }
        connected.at(B).push_back(A);

        costs[A][B] = C;
        costs[B][A] = C;
    }

    vector<long long> min_cost_from_1(N + 1, numeric_limits<long long>::max());
    min_cost_from_1.at(1) = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> queue;
    queue.push({0, 1});
    while (!queue.empty()) {
        auto top = queue.top();
        long long cost = top.first;
        int current = top.second;
        queue.pop();
        if (cost > min_cost_from_1.at(current)) {
            continue;
        }
        for (auto next: connected.at(current)) {
            long long possible_cost = min_cost_from_1.at(current) + costs.at(current).at(next);
            if (possible_cost < min_cost_from_1.at(next)) {
                min_cost_from_1.at(next) = possible_cost;
                // cout << "min_cost_from_1.at(" << next << "): " << min_cost_from_1.at(next) << endl;
                queue.push({possible_cost, next});
            }
        }
    }

    vector<long long> min_cost_from_n(N + 1, numeric_limits<long long>::max());
    min_cost_from_n.at(N) = 0;
    queue.push({0, N});
    while (!queue.empty()) {
        auto top = queue.top();
        long long cost = top.first;
        int current = top.second;
        queue.pop();
        if (cost > min_cost_from_n.at(current)) {
            continue;
        }
        for (auto next: connected.at(current)) {
            // cout << "current: " << current << ", next: " << next << endl;
            long long possible_cost = min_cost_from_n.at(current) + costs.at(current).at(next);
            // cout << "possible_cost: " << possible_cost << endl;
            // cout << "min_cost_from_n.at(" << next << "): " << min_cost_from_n.at(next) << endl;
            if (possible_cost < min_cost_from_n.at(next)) {
                min_cost_from_n.at(next) = possible_cost;
                // cout << "min_cost_from_n.at(" << next << "): " << min_cost_from_n.at(next) << endl;
                queue.push({possible_cost, next});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << min_cost_from_1.at(i) + min_cost_from_n.at(i) << endl;
    }
}
