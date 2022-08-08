#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;

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

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> deg(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        deg.at(U)++;
        deg.at(V)++;
    }

    int oddCount = 0;
    for (int i = 1; i <= N; i++) {
        if (deg.at(i) % 2 != 0) {
            oddCount++;
        }
    }
    int evenCount = N - oddCount;

    mint ans = 0;
    for (int i = 0; i <= K; i += 2) {
        if (i <= oddCount && K - i <= evenCount) {
            ans += nck(evenCount, K - i) * nck(oddCount, i);
        }
    }

    cout << ans.val() << endl;
}
