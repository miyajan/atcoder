#include <bits/stdc++.h>

using namespace std;

int main() {
    long double T;
    cin >> T;
    int L, X, Y;
    cin >> L >> X >> Y;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int E;
        cin >> E;

        long double x, y, z;
        x = 0;
        y = cos(-2 * E * M_PI / T - M_PI / 2) * L / 2;
        z = (sin(-2 * E * M_PI / T - M_PI / 2) + 1) * L / 2;
        // cout << "x: " << x << ", y: " << y << ", z: " << z << endl;

        cout << setprecision(15) << 90 - 180 * atan(sqrt((x - X) * (x - X) + (y - Y) * (y - Y)) / z) / M_PI << endl;
    }
}
