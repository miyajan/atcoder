/**
 * 想定解ではないが通ってしまった。
 * O(|N||K|) なので落ちそうなものだが、厳密には |N||K| より計算量は小さくなるから通ってしまうっぽい。
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    string ans;
    for (int i = 0; i < N; i++) {
        bool added = false;
        for (int j = max(0, K - N + i); j < (int) ans.length(); j++) {
            if (ans.at(j) > S.at(i)) {
                if (j == 0) {
                    ans = S.at(i);
                } else {
                    ans = ans.substr(0, j) + S.at(i);
                }
                added = true;
            }
        }
        if (!added && ans.length() < K) {
            ans += S.at(i);
        }
    }
    cout << ans << endl;
}
