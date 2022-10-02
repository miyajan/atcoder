#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    int a = N / 16;
    int b = N % 16;
    if (a == 10) {
        cout << 'A';
    } else if (a == 11) {
        cout << 'B';
    } else if (a == 12) {
        cout << 'C';
    } else if (a == 13) {
        cout << 'D';
    } else if (a == 14) {
        cout << 'E';
    } else if (a == 15) {
        cout << 'F';
    } else {
        cout << a;
    }

    if (b == 10) {
        cout << 'A';
    } else if (b == 11) {
        cout << 'B';
    } else if (b == 12) {
        cout << 'C';
    } else if (b == 13) {
        cout << 'D';
    } else if (b == 14) {
        cout << 'E';
    } else if (b == 15) {
        cout << 'F';
    } else {
        cout << b;
    }

    cout << endl;
}
