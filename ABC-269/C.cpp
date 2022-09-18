#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string to_binary(unsigned long long n) {
    return bitset<60>(n).to_string();
}

int main() {
    unsigned long long N;
    cin >> N;

    string binary_n = to_binary(N);

    vector<ll> bit_on;
    for (int i = 0; i < binary_n.length(); i++) {
        if (binary_n.at(i) == '1') {
            bit_on.push_back(i);
        }
    }

    string base;
    for (int i = 0; i < binary_n.length(); i++) {
        base += "0";
    }

    vector<unsigned long long> ans;
    for (int i = 0; i < (1 << bit_on.size()); i++) {
        string current = base;
        bitset<15> s(i);
        for (int j = 0; j < 15; j++) {
            if (s.test(j)) {
                current.at(bit_on.at(j)) = '1';
            }
        }
        unsigned long long x = stoull(current, nullptr, 2);
        ans.push_back(x);
    }

    std::sort(ans.begin(), ans.end());
    for (auto x: ans) {
        cout << x << endl;
    }
}
