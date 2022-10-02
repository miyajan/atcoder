#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a.at(i);
    }
    std::sort(a.begin(), a.end());

    map<ll, bool> exists;
    ll wildcard = 0;
    bool one = false;
    deque<ll> dq;
    for (int i = 1; i <= N; i++) {
        if (exists.find(a.at(i)) == exists.end()) {
            dq.push_back(a.at(i));
            exists[a.at(i)] = true;
        } else {
            if (one) {
                wildcard++;
                one = false;
            } else {
                one = true;
            }
        }
    }

    ll ans = 0;
    while (!dq.empty() || wildcard > 0) {
//        cout << "ans: " << ans << ", dq.size(): " << dq.size() << endl;
        if (!dq.empty() && dq.front() == ans + 1) {
            ans++;
            dq.pop_front();
        } else {
            if (wildcard) {
                ans++;
                wildcard--;
            } else {
                if (one && dq.size() > 0) {
                    one = false;
                    dq.pop_back();
                    ans++;
                } else if (dq.size() > 1) {
                    ans++;
                    dq.pop_back();
                    dq.pop_back();
                } else {
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}
