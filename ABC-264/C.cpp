#include <bits/stdc++.h>

using namespace std;

int main() {
    int H1, W1;
    cin >> H1 >> W1;

    vector<vector<long long>> A(H1 + 1, vector<long long>(W1 + 1));
    for (int i = 1; i <= H1; i++) {
        for (int j = 1; j <= W1; j++) {
            cin >> A.at(i).at(j);
        }
    }

    int H2, W2;
    cin >> H2 >> W2;
    vector<vector<long long>> B(H2 + 1, vector<long long>(W2 + 1));
    for (int i = 1; i <= H2; i++) {
        for (int j = 1; j <= W2; j++) {
            cin >> B.at(i).at(j);
        }
    }

    long long h1_counter = 1;
    for (int i = 0; i < H1; i++) {
        h1_counter *= 2;
    }
    long long w1_counter = 1;
    for (int i = 0; i < W1; i++) {
        w1_counter *= 2;
    }

//    cout << "h1_counter: " << h1_counter << endl;
//    cout << "w1_counter: " << w1_counter << endl;
    for (int i = 0; i < h1_counter; i++) {
        for (int j = 0; j < w1_counter; j++) {
//            i = 10;
//            j = 13;
            int b_h = 1;
            bool yes = true;
            for (int k = 1; k <= H1; k++) {
                int b_w = 1;
                if ((i >> (k - 1) & 1) != 1) {
                    continue;
                }
//                cout << "k: " << k << endl;
//                cout << "b_h: " << b_h << endl;
                for (int l = 1; l <= W1; l++) {
                    if ((j >> (l - 1) & 1) != 1) {
                        continue;
                    }
//                    cout << "l: " << l << endl;
//                    cout << "b_w: " << b_w << endl;
                    if (b_h > H2 || b_w > W2) {
                        yes = false;
                        break;
                    }

                    if (A.at(k).at(l) == B.at(b_h).at(b_w)) {
//                        cout << "A.at(" << k << ").at(" << l << "): " << A.at(k).at(l) << endl;
//                        cout << "B.at(" << b_h << ").at(" << b_w << "): " << B.at(b_h).at(b_w) << endl;
                        b_w++;
                    } else {
                        yes = false;
                        break;
                    }
                }
                if (b_w != W2 + 1) {
                    yes = false;
                }
                if (!yes) {
                    break;
                }
                b_h++;
            }
            if (b_h != H2 + 1) {
                yes = false;
            }
            if (yes) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
