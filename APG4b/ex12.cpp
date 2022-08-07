#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    int ans = 1;
    for (int i = 1; i < S.size(); i += 2) {
        if (S.at(i) == '+') {
            ans++;
        } else {
            ans--;
        }
    }
    cout << ans << endl;
}
