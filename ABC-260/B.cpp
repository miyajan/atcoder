#include <bits/stdc++.h>

using namespace std;

bool sortByScore(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    long long N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    vector<int> A(N), B(N);
    vector<pair<int, int>> studentMath(N);
    vector<pair<int, int>> studentEnglish(N);
    vector<pair<int, int>> studentTotal(N);


    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        studentMath.at(i) = {i + 1, A.at(i)};
    }
    for (int i = 0; i < N; i++) {
        cin >> B.at(i);
        studentEnglish.at(i) = {i + 1, B.at(i)};
        studentTotal.at(i) = {i + 1, A.at(i) + B.at(i)};
    }

    set<int> success;
    sort(studentMath.begin(), studentMath.end(), sortByScore);
    sort(studentEnglish.begin(), studentEnglish.end(), sortByScore);
    sort(studentTotal.begin(), studentTotal.end(), sortByScore);

    for (int i = 0; i < X; i++) {
        success.insert(studentMath.at(i).first);
    }
    int i = 0;
    while (Y > 0) {
        if (success.find(studentEnglish.at(i).first) == success.end()) {
            success.insert(studentEnglish.at(i).first);
            Y--;
        }
        i++;
    }
    i = 0;
    while (Z > 0) {
        if (success.find(studentTotal.at(i).first) == success.end()) {
            success.insert(studentTotal.at(i).first);
            Z--;
        }
        i++;
    }
    for (int x: success) {
        cout << x << endl;
    }
}
