#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string gen(set<string> &exists, vector<string> &S, ll left_underscore_length, ll current_index, string current_string) {
    current_string = current_string + S.at(current_index);
    if (current_index == S.size() - 1) {
//        cout << "current_string: " << current_string << endl;
        if (current_string.length() >= 3 && exists.find(current_string) == exists.end()) {
            return current_string;
        } else {
            return "-1";
        }
    }

    for (int i = 1; i <= left_underscore_length - (S.size() - current_index - 2); i++) {
        current_string += "_";
        string next = gen(exists, S, left_underscore_length - i, current_index + 1, current_string);
        if (next != "-1") {
            return next;
        }
    }

    return "-1";
}

int main() {
    ll N, M;
    cin >> N >> M;

    ll total_s_length = 0;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S.at(i);
        total_s_length += S.at(i).length();
    }
    ll max_underscore_length = 16 - total_s_length;
    sort(S.begin(), S.end());

    set<string> exists;
    for (int i = 0; i < M; i++) {
        string T;
        cin >> T;
        exists.insert(T);
    }

    do {
        string next = gen(exists, S, max_underscore_length, 0, "");
        if (next != "-1") {
            cout << next << endl;
            return 0;
        }
    } while (next_permutation(S.begin(), S.end()));

    cout << "-1" << endl;
}
