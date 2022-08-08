#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(51, 0);
    // cout << N << endl;
    for (int i = 2; i <= N; i++) {
        cin >> P.at(i);
        // cout << "P.at(" << i << "): " << P.at(i) << endl;
    }
    int current = N;
    int ans = 0;
    while (current != 1) {
        // cout << "current: " << current << endl;
        current = P.at(current);
        ans++;
    }
    cout << ans << endl;
}
