#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;

    if (S.at(0) != S.at(1) && S.at(0) != S.at(2)) {
        cout << S.at(0) << endl;
    } else if (S.at(0) == S.at(1) && S.at(1) != S.at(2)) {
        cout << S.at(2) << endl;
    } else if (S.at(0) == S.at(1) && S.at(1) == S.at(2)) {
        cout << "-1" << endl;
    } else if (S.at(0) == S.at(2) && S.at(0) != S.at(1)) {
        cout << S.at(1) << endl;
    }
}
