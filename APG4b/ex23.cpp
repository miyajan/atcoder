#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    cin >> N;

    map<long long, long long> valueCount;
    for (int i = 0; i < N; i++) {
        long long A;
        cin >> A;
        if (valueCount.count(A)) {
            valueCount.at(A)++;
        } else {
            valueCount[A] = 1;
        }
    }

    long long value;
    long long count = 0;
    for (auto [v, c]: valueCount) {
        if (c > count) {
            value = v;
            count = c;
        }
    }
    cout << value << " " << count << endl;
}
