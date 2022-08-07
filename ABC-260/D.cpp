#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P.at(i);
    }

    vector<long long> ans(N, -1);
    map<long long, vector<long long>> numToCards;

    for (int i = 0; i < N; i++) {
        long long x = P.at(i);
        auto found = numToCards.lower_bound(x);
        if (found == numToCards.end()) {
            numToCards[x] = {x};
        } else {
            numToCards[x] = move(numToCards[found->first]);
            numToCards[x].push_back(x);
            numToCards.erase(found);
        }
        if (numToCards[x].size() >= K) {
            for (long long card: numToCards[x]) {
                ans.at(card - 1) = i + 1;
            }
            numToCards.erase(x);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
}
