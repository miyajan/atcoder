#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    int total = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        total += A.at(i);
    }

    int average = total / N;
    for (int i = 0; i < N; i++) {
        cout << abs(A.at(i) - average) << endl;
    }
}
