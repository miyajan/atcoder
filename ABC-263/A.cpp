#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    vector<int> count(14, 0);
    count.at(A)++;
    count.at(B)++;
    count.at(C)++;
    count.at(D)++;
    count.at(E)++;
    bool three = false;
    bool two = false;
    for (int i = 1; i <= 13; i++) {
        if (count.at(i) == 3) {
            three = true;
        } else if (count.at(i) == 2) {
            two = true;
        }
    }
    if (three && two) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
