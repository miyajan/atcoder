#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> a(N + 1);
    vector<int> b(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a.at(i) >> b.at(i);
    }

    vector<vector<pair<bool, vector<int>>>> dp(N + 1, vector<pair<bool, vector<int>>>(10001));
    dp.at(1).at(a.at(1)) = {true, {a.at(1)}};
    dp.at(1).at(b.at(1)) = {true, {b.at(1)}};
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= S; j++) {
            if (dp.at(i - 1).at(j).first) {
//                cout << "i-1: " << i - 1 << ", j: " << j << endl;
                if (j + a.at(i) <= S && !dp.at(i).at(j + a.at(i)).first) {
                    vector<int> x = dp.at(i - 1).at(j).second;
                    x.push_back(a.at(i));
                    dp.at(i).at(j + a.at(i)) = {true, x};
                }
                if (j + b.at(i) <= S && !dp.at(i).at(j + b.at(i)).first) {
                    vector<int> x = dp.at(i - 1).at(j).second;
                    x.push_back(b.at(i));
                    dp.at(i).at(j + b.at(i)) = {true, x};
                }
            }
        }
    }

    if (dp.at(N).at(S).first) {
        cout << "Yes" << endl;
        vector<int> x = dp.at(N).at(S).second;
        for (int i = 1; i <= N; i++) {
            if (x.at(i - 1) == a.at(i)) {
                cout << "H";
            } else {
                cout << "T";
            }
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
}
