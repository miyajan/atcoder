#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, X, Y;
    cin >> N >> X >> Y;

    long long redCount = 1;
    long long blueCount = 0;
    for (int level = N; level > 1; level--) {
        blueCount += redCount * X;
        redCount += blueCount;
        blueCount *= Y;
    }

    cout << blueCount << endl;
}
