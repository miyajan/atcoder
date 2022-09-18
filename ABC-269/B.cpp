#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    vector<string> S(11);
    for (int i = 1; i <= 10; i++) {
        cin >> S.at(i);
    }

    ll A, B, C, D;
    A = 0;
    B = 0;
    C = 0;
    D = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (A == 0 && C == 0 && S.at(i).at(j - 1) == '#') {
                A = i;
                C = j;

                for (int k = i + 1; k <= 10; k++) {
                    if (B == 0 && S.at(k).at(j - 1) == '.') {
                        B = k - 1;
                    }
                    if (B == 0 && S.at(k).at(j - 1) == '#' && k == 10) {
                        B = 10;
                    }
                }
                if (i == 10) {
                    B = 10;
                }
            }
            if (A != 0 && C != 0 && D == 0 && S.at(i).at(j - 1) == '.') {
                D = j - 1;
            }
            if (A != 0 && C != 0 && D == 0 && S.at(i).at(j - 1) == '#' && j == 10) {
                D = 10;
            }
        }
    }

    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}
