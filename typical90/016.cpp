#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, A, B, C;
    cin >> N >> A >> B >> C;

    long long ans = 10000;
    for (int i = 0; i <= 9999; i++) {
        for (int j = 0; j <= 9999 - i; j++) {
            long long x = N - A * i - B * j;
            if (x < 0) {
                continue;
            }
            if (x % C == 0) {
                ans = min(ans, i + j + x / C);
            }
        }
    }

    cout << ans << endl;
}
