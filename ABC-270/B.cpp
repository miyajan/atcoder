#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    if (X > 0) {
        if (Y < 0 || X < Y) {
            cout << X << endl;
        } else {
            if (Z < Y) {
                if (Z < 0) {
                    cout << 2 * (-Z) + X << endl;
                } else {
                    cout << X << endl;
                }
            } else {
                cout << -1 << endl;
            }
        }
    } else {
        if (Y > 0 || X > Y) {
            cout << -X << endl;
        } else {
            if (Z > Y) {
                if (Z > 0) {
                    cout << 2 * Z + (-X) << endl;
                } else {
                    cout << -X << endl;
                }
            } else {
                cout << -1 << endl;
            }
        }
    }
}
