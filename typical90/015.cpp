#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint1000000007;

mint fact(const int n) {
    static vector<mint> fact = {1};
    while ((int) fact.size() <= n) {
        fact.push_back(fact.back() * fact.size());
    }
    return fact.at(n);
}

mint inv_fact(const int n) {
    static vector<mint> inv = {0, 1};
    static vector<mint> inv_fact = {1, 1};
    while ((int) inv_fact.size() <= n) {
        int i = (int) inv_fact.size();
        inv.push_back(-mint(mint::mod() / i) * inv.at(mint::mod() % i));
        inv_fact.push_back(inv_fact.back() * inv.back());
    }
    return inv_fact.at(n);
}

mint nck(const int n, const int k) {
    return fact(n) * inv_fact(k) * inv_fact(n - k);
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        mint ans = 0;
        int max_j = (N % i == 0) ? N / i : N / i + 1;
        for (int j = 1; j <= max_j; j++) {
            ans += nck(N - (i - 1) * (j - 1), j);
        }
        cout << ans.val() << endl;
    }
}
