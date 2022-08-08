#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> a.at(i);
    }

    long long justPos = 0;
    long long revPos = 0;
    for (int i = 1; i <= N; i++) {
        if (a.at(i) == i) {
            justPos++;
        } else if (a.at(a.at(i)) == i) {
            revPos++;
        }
    }

    long long ans = 0;
    if (justPos >= 2) {
        ans += (justPos * (justPos - 1)) / 2;
    }
    ans += revPos / 2;

    cout << ans << endl;
}
