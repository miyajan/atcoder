#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    double ans = 3.5;
    for (int i = 1; i < N; i++) {
        double next_ans = 0.0;
        for (int j = 1; j <= 6; j++) {
            if (j > ans) {
                next_ans += (double) j / 6.0;
            } else {
                next_ans += ans / 6.0;
            }
        }
        ans = next_ans;
    }
    cout << setprecision(10) << ans << endl;
}
