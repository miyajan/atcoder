#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    cin >> N;
    map<string, int> strCountMap;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (strCountMap.find(s) == strCountMap.end()) {
            cout << s << endl;
            strCountMap[s] = 1;
        } else {
            cout << s << "(" << strCountMap.at(s) << ")" << endl;
            strCountMap.at(s)++;
        }
    }
}
