#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int start = 1;
    int end = N;
    while (start != end) {
        int A = start;
        int B = (start + end) / 2;
        int C = 1;
        int D = N;
        cout << "? " << A << " " << B << " " << C << " " << D << endl;

        int T;
        cin >> T;

        if (T > B - A) {
            start = B + 1;
        } else {
            end = B;
        }
    }

    int X = start;

    start = 1;
    end = N;
    while (start != end) {
        int A = 1;
        int B = N;
        int C = start;
        int D = (start + end) / 2;
        cout << "? " << A << " " << B << " " << C << " " << D << endl;

        int T;
        cin >> T;

        if (T > D - C) {
            start = D + 1;
        } else {
            end = D;
        }
    }

    int Y = start;

    cout << "! " << X << " " << Y << endl;
}
