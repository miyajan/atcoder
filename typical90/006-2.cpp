/**
 * 想定解
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector<int>> next(N + 1, vector<int>(26, N));
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (S.at(i) == 'a' + j) {
                next.at(i).at(j) = i;
            } else {
                next.at(i).at(j) = next.at(i + 1).at(j);
            }
        }
    }

    string ans;
    int current_pos = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 26; j++) {
            int next_pos = next.at(current_pos).at(j);
            int max_possible_length = N - 1 - next_pos + i + 1;
            if (max_possible_length >= K) {
                ans += (char) ('a' + j);
                current_pos = next_pos + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}
