/**
 * 参考
 * https://drken1215.hatenablog.com/entry/2018/06/08/210000
 * https://atcoder.jp/contests/abc262/submissions/33405206
 */
#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

// ここから

using mint = atcoder::modint998244353;

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

// ここまでコピペする

int main() {
}
