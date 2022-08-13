#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    if (R == 1 || R == 15) {
        cout << "black" << endl;
    } else if (R == 2 || R == 14) {
        if (2 <= C && C <= 14) {
            cout << "white" << endl;
        } else {
            cout << "black" << endl;
        }
    } else if (R == 3 || R == 13) {
        if (C != 2 && C != 14) {
            cout << "black" << endl;
        } else {
            cout << "white" << endl;
        }
    } else if (R == 4 || R == 12) {
        if (C == 2 || C == 4 || (4 <= C && C <= 12)) {
            cout << "white" << endl;
        } else {
            cout << "black" << endl;
        }
    } else if (R == 5 || R == 11) {
        if (C == 2 || C == 4 || C == 12 || C == 14) {
            cout << "white" << endl;
        } else {
            cout << "black" << endl;
        }
    } else if (R == 6 || R == 10) {
        if (C == 2 || C == 4 || (6 <= C && C <= 10)) {
            cout << "white" << endl;
        } else {
            cout << "black" << endl;
        }
    } else if (R == 7 || R == 9) {
        if (C == 2 || C == 4 || C == 6 || C == 10 || C == 12 || C == 14) {
            cout << "white" << endl;
        } else {
            cout << "black" << endl;
        }
    } else if (R == 8) {
        if (C == 2 || C == 4 || C == 6 || C == 8 || C == 10 || C == 12 || C == 14) {
            cout << "white" << endl;
        } else {
            cout << "black" << endl;
        }
    }
}
