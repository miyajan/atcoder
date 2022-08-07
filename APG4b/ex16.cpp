#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> data(5);
    for (int i = 0; i < 5; i++) {
        cin >> data.at(i);
    }

    int prev = -1;
    for (int x : data) {
        if (x == prev) {
            cout << "YES" << endl;
            return 0;
        }
        prev = x;
    }

    cout << "NO" << endl;
}
