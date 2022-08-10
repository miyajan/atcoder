#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using modint = atcoder::modint1000000007;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<modint> r(N + 1, 0);
    vector<modint> er(N + 1, 0);
    vector<modint> der(N + 1, 0);
    vector<modint> oder(N + 1, 0);
    vector<modint> coder(N + 1, 0);
    vector<modint> tcoder(N + 1, 0);
    vector<modint> atcoder(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        r.at(i) = r.at(i + 1);
        er.at(i) = er.at(i + 1);
        der.at(i) = der.at(i + 1);
        oder.at(i) = oder.at(i + 1);
        coder.at(i) = coder.at(i + 1);
        tcoder.at(i) = tcoder.at(i + 1);
        atcoder.at(i) = atcoder.at(i + 1);

        if (S.at(i) == 'r') {
            r.at(i) = r.at(i + 1) + 1;
        } else if (S.at(i) == 'e') {
            er.at(i) = er.at(i + 1) + r.at(i + 1);
        } else if (S.at(i) == 'd') {
            der.at(i) = der.at(i + 1) + er.at(i + 1);
        } else if (S.at(i) == 'o') {
            oder.at(i) = oder.at(i + 1) + der.at(i + 1);
        } else if (S.at(i) == 'c') {
            coder.at(i) = coder.at(i + 1) + oder.at(i + 1);
        } else if (S.at(i) == 't') {
            tcoder.at(i) = tcoder.at(i + 1) + coder.at(i + 1);
        } else if (S.at(i) == 'a') {
            atcoder.at(i) = atcoder.at(i + 1) + tcoder.at(i + 1);
        }
//        cout << "S.at(i): " << S.at(i) << endl;
//        cout << "r.at(i): " << r.at(i).val() << endl;
//        cout << "er.at(i): " << er.at(i).val() << endl;
//        cout << "der.at(i): " << der.at(i).val() << endl;
//        cout << "oder.at(i): " << oder.at(i).val() << endl;
//        cout << "coder.at(i): " << coder.at(i).val() << endl;
//        cout << "tcoder.at(i): " << tcoder.at(i).val() << endl;
//        cout << "atcoder.at(i): " << atcoder.at(i).val() << endl;
    }
    cout << atcoder.at(0).val() << endl;
}
