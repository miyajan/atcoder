#include <bits/stdc++.h>

using namespace std;

string S, T;

int main() {
    cin >> S >> T;

    long long sIndex = 0;
    long long tIndex = 0;

    while (tIndex < T.length()) {
        if (sIndex < S.length() && S[sIndex] == T[tIndex]) {
            sIndex++;
            tIndex++;
        } else {
            if (sIndex > 1 && S[sIndex -2] == S[sIndex - 1] && S[sIndex - 1] == T[tIndex]) {
                tIndex++;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
