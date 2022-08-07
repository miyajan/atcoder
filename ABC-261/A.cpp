#include <bits/stdc++.h>

using namespace std;

int main() {
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    bitset<101> red;
    bitset<101> blue;

    for (int i = L1; i <= R1; i++) {
        red.set(i);
    }
    for (int i = L2; i <= R2; i++) {
        blue.set(i);
    }
    int ans = 0;
    bool before = false;
    for (int i = 0; i <= 100; i++) {
        if (red.test(i) && blue.test(i)) {
            if (before) {
                ans++;
            } else {
                before = true;
            }
        } else {
            before = false;
        }
    }
    cout << ans << endl;
}
