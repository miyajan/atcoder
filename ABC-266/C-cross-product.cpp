#include <bits/stdc++.h>

using namespace std;

int main() {
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    bool yes = true;
    if ((Cx - Bx) * (Ay - By) - (Cy - By) * (Ax - Bx) < 0) {
        yes = false;
    }
    if ((Dx - Cx) * (By - Cy) - (Dy - Cy) * (Bx - Cx) < 0) {
        yes = false;
    }
    if ((Ax - Dx) * (Cy - Dy) - (Ay - Dy) * (Cx - Dx) < 0) {
        yes = false;
    }
    if ((Bx - Ax) * (Dy - Ay) - (By - Ay) * (Dx - Ax) < 0) {
        yes = false;
    }
    if (yes) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
