#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S, T;
    cin >> S >> T;

    if (S.length() > T.length()) {
        cout << "No" << endl;
        return 0;
    }

    string ans = "Yes";
    for (int i = 0; i < S.length(); i++) {
        if (S.at(i) != T.at(i)) {
            ans = "No";
            break;
        }
    }

    cout << ans << endl;
}
