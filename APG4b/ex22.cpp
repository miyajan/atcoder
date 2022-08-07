#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    map<long long, long long> bToA;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        bToA[b] = a;
    }

    for (auto [b, a]: bToA) {
        cout << a << " " << b << endl;
    }
}
