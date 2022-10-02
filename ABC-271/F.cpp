#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<ll>> a(N + 1, vector<ll>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a.at(i).at(j);
        }
    }

    vector<vector<unordered_map<ll, ll>>> value_counts_from_start(N + 1, vector<unordered_map<ll, ll>>(N + 1));
    value_counts_from_start.at(1).at(1)[a.at(1).at(1)] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i + j > N) {
                break;
            }

            for (auto [value, count]: value_counts_from_start.at(i).at(j)) {
                if (i < N) {
                    ll x = value ^ a.at(i + 1).at(j);
                    if (value_counts_from_start.at(i + 1).at(j).find(x) ==
                        value_counts_from_start.at(i + 1).at(j).end()) {
                        value_counts_from_start.at(i + 1).at(j)[x] = count;
                    } else {
                        value_counts_from_start.at(i + 1).at(j).at(x) += count;
                    }
//                    cout << "value_counts_from_start[" << i + 1 << "][" << j << "][" << x << "] = "
//                         << value_counts_from_start.at(i + 1).at(j).at(x) << endl;
                }
                if (j < N) {
                    ll x = value ^ a.at(i).at(j + 1);
                    if (value_counts_from_start.at(i).at(j + 1).find(x) ==
                        value_counts_from_start.at(i).at(j + 1).end()) {
                        value_counts_from_start.at(i).at(j + 1)[x] = count;
                    } else {
                        value_counts_from_start.at(i).at(j + 1).at(x) += count;
                    }
//                    cout << "value_counts_from_start[" << i << "][" << j + 1 << "][" << x << "] = "
//                         << value_counts_from_start.at(i).at(j + 1).at(x) << endl;
                }
            }
        }
    }

    vector<vector<unordered_map<ll, ll>>> value_counts_from_end(N + 1, vector<unordered_map<ll, ll>>(N + 1));
    value_counts_from_end.at(N).at(N)[a.at(N).at(N)] = 1;
    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= 1; j--) {
            if (i + j <= N + 2) {
                break;
            }

            for (auto [value, count]: value_counts_from_end.at(i).at(j)) {
                if (i > 1) {
                    ll x = value ^ a.at(i - 1).at(j);
                    if (value_counts_from_end.at(i - 1).at(j).find(x) ==
                        value_counts_from_end.at(i - 1).at(j).end()) {
                        value_counts_from_end.at(i - 1).at(j)[x] = count;
                    } else {
                        value_counts_from_end.at(i - 1).at(j).at(x) += count;
                    }
//                    cout << "value_counts_from_end[" << i - 1 << "][" << j << "][" << x << "] = "
//                         << value_counts_from_end.at(i - 1).at(j).at(x) << endl;
                }
                if (j > 1) {
                    ll x = value ^ a.at(i).at(j - 1);
                    if (value_counts_from_end.at(i).at(j - 1).find(x) ==
                        value_counts_from_end.at(i).at(j - 1).end()) {
                        value_counts_from_end.at(i).at(j - 1)[x] = count;
                    } else {
                        value_counts_from_end.at(i).at(j - 1).at(x) += count;
                    }
//                    cout << "value_counts_from_end[" << i << "][" << j - 1 << "][" << x << "] = "
//                         << value_counts_from_end.at(i).at(j - 1).at(x) << endl;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int j = N + 1 - i;
        for (auto [value, count]: value_counts_from_start.at(i).at(j)) {
            if (i < N) {
                if (value_counts_from_end.at(i + 1).at(j).find(value) != value_counts_from_end.at(i + 1).at(j).end()) {
                    ans += count * value_counts_from_end.at(i + 1).at(j).at(value);
                }
            }
            if (j < N) {
                if (value_counts_from_end.at(i).at(j + 1).find(value) != value_counts_from_end.at(i).at(j + 1).end()) {
                    ans += count * value_counts_from_end.at(i).at(j + 1).at(value);
                }
            }
        }
    }

    cout << ans << endl;
}
