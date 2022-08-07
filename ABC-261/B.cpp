#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, map<int, char>> m;
    bool correct = true;
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (j > i) {
                m[i][j] = a[j];
            } else {
                if (m[j][i] == 'W' && a[j] != 'L') {
                    correct = false;
                } else if (m[j][i] == 'D' && a[j] != 'D') {
                    correct = false;
                } else if (m[j][i] == 'L' && a[j] != 'W') {
                    correct = false;
                }
            }
        }
    }
    if (correct) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }
}
