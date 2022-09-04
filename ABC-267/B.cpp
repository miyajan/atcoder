#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    if (S.at(0) == '1') {
        cout << "No" << endl;
        return 0;
    }

    vector<bool> pinExists(8, false);
    if (S.at(0) == '1' || S.at(4) == '1') {
        pinExists.at(4) = true;
    }
    if (S.at(1) == '1' || S.at(7) == '1') {
        pinExists.at(3) = true;
    }
    if (S.at(2) == '1' || S.at(8) == '1') {
        pinExists.at(5) = true;
    }
    if (S.at(3) == '1') {
        pinExists.at(2) = true;
    }
    if (S.at(5) == '1') {
        pinExists.at(6) = true;
    }
    if (S.at(6) == '1') {
        pinExists.at(1) = true;
    }
    if (S.at(9) == '1') {
        pinExists.at(7) = true;
    }
//    for (int i = 1; i <= 7; i++) {
//        cout << "pinExists[" << i << "] = " << pinExists[i] << endl;
//    }

    bool isSplit = false;
    for (int i = 1; i <= 7; i++) {
        for (int j = i + 1; j <= 7; j++) {
            if (pinExists.at(i) && pinExists.at(j)) {
                for (int k = i + 1; k < j; k++) {
                    if (!pinExists.at(k)) {
                        isSplit = true;
                    }
                }
            }
        }
    }

    if (isSplit) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
