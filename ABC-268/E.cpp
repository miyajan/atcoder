#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using ll = long long;
using mint = atcoder::modint;

int main() {
    ll N;
    cin >> N;

    atcoder::modint::set_mod(N);

    vector<ll> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p.at(i);
    }

    ll plus = 0;
    ll normal = 0;
    ll minus = 0;
    vector<ll> start(N, 0);
    vector<ll> end(N, 0);
    ll current_score = 0;
    for (int i = 0; i < N; i++) {
        mint x = i - p.at(i);
        mint y = p.at(i) - i;
//        cout << "i: " << i << ", p[" << i << "]: " << p.at(i) << ", x: " << x.val() << ", y: " << y.val() << endl;
        current_score += min(x.val(), y.val());

        start.at(y.val())++;
        end.at((y + N / 2).val())++;

        if (x == N / 2) {
            if (N % 2 == 1) {
//                cout << "p[" << i << "]: " << p.at(i) << ": normal" << endl;
                normal++;
            } else {
//                cout << "p[" << i << "]: " << p.at(i) << ": minus" << endl;
                minus++;
            }
        } else if (x.val() >= 0 && x.val() < N / 2) {
//            cout << "p[" << i << "]: " << p.at(i) << ": plus" << endl;
            plus++;
        } else {
//            cout << "p[" << i << "]: " << p.at(i) << ": minus" << endl;
            minus++;
        }
    }

//    for (int i = 0; i < N; i++) {
//        cout << "start[" << i << "]: " << start.at(i) << endl;
//        cout << "end[" << i << "]: " << end.at(i) << endl;
//    }
//
//    cout << "scores[0]: " << current_score << endl;

    ll ans = current_score;
    for (int i = 1; i < N; i++) {
//        cout << "plus: " << plus << endl;
//        cout << "normal: " << normal << endl;
//        cout << "minus: " << minus << endl;

        current_score = current_score + plus - minus;
//        cout << "scores[" << i << "]: " << current_score << endl;

        ans = min(ans, current_score);

        plus = plus + start.at(i) - end.at(i);
        minus = (N % 2 == 0) ? minus - start.at(i) + end.at(i) : minus - start.at(i) + normal;
        normal = (N % 2 == 0) ? 0 : end.at(i);
    }

    cout << ans << endl;
}
