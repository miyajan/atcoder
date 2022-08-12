#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int Q;
    cin >> Q;

    vector<vector<bool>> is_red(H + 2, vector<bool>(W + 2));
    auto dsu = atcoder::dsu(100000000);

    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            is_red.at(r).at(c) = true;
            if (is_red.at(r - 1).at(c)) {
                dsu.merge(r * 10000 + c, (r - 1) * 10000 + c);
            }
            if (is_red.at(r).at(c - 1)) {
                dsu.merge(r * 10000 + c, r * 10000 + (c - 1));
            }
            if (is_red.at(r).at(c + 1)) {
                dsu.merge(r * 10000 + c, r * 10000 + (c + 1));
            }
            if (is_red.at(r + 1).at(c)) {
                dsu.merge(r * 10000 + c, (r + 1) * 10000 + c);
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            if (is_red.at(ra).at(ca) && is_red.at(rb).at(cb) && dsu.same(ra * 10000 + ca, rb * 10000 + cb)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
