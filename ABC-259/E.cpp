#include <bits/stdc++.h>

using namespace std;

long long N;

int main() {
    cin >> N;
    long long m[N];
    vector<vector<long long>> p;
    vector<vector<long long>> e;
    map<long long, pair<long long, long long>> peMaxMap;

    for (int i = 0; i < N; i++) {
        cin >> m[i];
        p.push_back(vector<long long>(m[i]));
        e.push_back(vector<long long>(m[i]));
        for (int j = 0; j < m[i]; j++) {
            cin >> p[i][j] >> e[i][j];
            if (peMaxMap.count(p[i][j]) > 0) {
                if (e[i][j] > peMaxMap[p[i][j]].first) {
                    peMaxMap[p[i][j]] = {e[i][j], 1};
                } else if (e[i][j] == peMaxMap[p[i][j]].first) {
                    peMaxMap[p[i][j]] = {e[i][j], peMaxMap[p[i][j]].second + 1};
                }
            } else {
                peMaxMap[p[i][j]] = {e[i][j], 1};
            }
        }
    }

    long long ans = 0;
    bool found = false;
    for (int i = 0; i < N; i++) {
        bool increase = false;
        for (int j = 0; j < m[i]; j++) {
            if (peMaxMap[p[i][j]].first == e[i][j] && peMaxMap[p[i][j]].second == 1) {
                increase = true;
            }
        }
        if (increase) {
            ans++;
        } else if (!found) {
            ans++;
            found = true;
        }
    }

    cout << ans << endl;
}
