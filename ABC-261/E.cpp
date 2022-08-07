#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, C;
    cin >> N >> C;
    vector<vector<pair<bool, bool>>> flip(N);

    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        long long A;
        cin >> A;
        bitset<32> bitA(A);
        flip.at(i) = vector<pair<bool, bool>>(32);
        for (int j = 0; j < 32; j++) {
            if (T == 1) {
                if (bitA.test(j)) {
                    flip.at(i).at(j).first = i == 0 ? false : flip.at(i - 1).at(j).first;
                    flip.at(i).at(j).second = i == 0 ? false : flip.at(i - 1).at(j).second;
                } else {
                    flip.at(i).at(j).first = false;
                    flip.at(i).at(j).second = true;
                }
            } else if (T == 2) {
                if (bitA.test(j)) {
                    flip.at(i).at(j).first = true;
                    flip.at(i).at(j).second = false;
                } else {
                    flip.at(i).at(j).first = i == 0 ? false : flip.at(i - 1).at(j).first;
                    flip.at(i).at(j).second = i == 0 ? false : flip.at(i - 1).at(j).second;
                }
            } else {
                if (bitA.test(j)) {
                    flip.at(i).at(j).first = i == 0 ? true : !flip.at(i - 1).at(j).first;
                    flip.at(i).at(j).second = i == 0 ? true : !flip.at(i - 1).at(j).second;
                } else {
                    flip.at(i).at(j).first = i == 0 ? false : flip.at(i - 1).at(j).first;
                    flip.at(i).at(j).second = i == 0 ? false : flip.at(i - 1).at(j).second;
                }
            }
        }
    }

    bitset<32> bitC(C);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++) {
            if ((!bitC.test(j) && flip.at(i).at(j).first) || (bitC.test(j) && flip.at(i).at(j).second)) {
                bitC.flip(j);
            }
        }
        cout << bitC.to_ullong() << endl;
    }
}
