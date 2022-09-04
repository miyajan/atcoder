#include <bits/stdc++.h>

using namespace std;

int main() {
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    double cosABC = ((Ax - Bx) * (Cx - Bx) + (Ay - By) * (Cy - By)) /
                    (sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By)) *
                     sqrt((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy)));
    double radABC = acos(cosABC);

    double cosBCD = ((Bx - Cx) * (Dx - Cx) + (By - Cy) * (Dy - Cy)) /
                    (sqrt((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy)) *
                     sqrt((Cx - Dx) * (Cx - Dx) + (Cy - Dy) * (Cy - Dy)));
    double radBCD = acos(cosBCD);

    double cosCDA = ((Cx - Dx) * (Ax - Dx) + (Cy - Dy) * (Ay - Dy)) /
                    (sqrt((Cx - Dx) * (Cx - Dx) + (Cy - Dy) * (Cy - Dy)) *
                     sqrt((Dx - Ax) * (Dx - Ax) + (Dy - Ay) * (Dy - Ay)));
    double radCDA = acos(cosCDA);

    double cosDAB = ((Dx - Ax) * (Bx - Ax) + (Dy - Ay) * (By - Ay)) /
                    (sqrt((Dx - Ax) * (Dx - Ax) + (Dy - Ay) * (Dy - Ay)) *
                     sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By)));
    double radDAB = acos(cosDAB);

//    cout << radABC << endl;
//    cout << radBCD << endl;
//    cout << radCDA << endl;
//    cout << radDAB << endl;

    if ((radABC + radBCD + radCDA - 0.00001 < radDAB && radDAB < radABC + radBCD + radCDA + 0.00001) ||
        (radBCD + radCDA + radDAB - 0.00001 < radABC && radABC < radBCD + radCDA + radDAB + 0.00001) ||
        (radCDA + radDAB + radABC - 0.00001 < radBCD && radBCD < radCDA + radDAB + radABC + 0.00001) ||
        (radDAB + radABC + radBCD - 0.00001 < radCDA && radCDA < radDAB + radABC + radBCD + 0.00001)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
