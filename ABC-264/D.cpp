#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    string atcoder = "atcoder";
    int count = 0;
    for (int i = 0; i < atcoder.length(); i++) {
        for (int j = 0; j < S.length(); j++) {
            if (S.at(j) == atcoder.at(i) && j != i) {
                for (int k = j - 1; k >= i; k--) {
                    S.at(k + 1) = S.at(k);
                    count++;
                }
                S.at(i) = atcoder.at(i);
                // cout << S << endl;
            }
        }
    }
    cout << count << endl;
}
