#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    vector<long long> A(N + 1), B(N + 1);
    map<long long, vector<long long>> aMap;
    map<long long, vector<long long>> bMap;
    long long start = 1;
    long long end = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A.at(i) >> B.at(i);

        if (aMap.find(A.at(i)) == aMap.end()) {
            aMap[A.at(i)] = {i};
        } else {
            aMap.at(A.at(i)).push_back(i);
        }

        if (bMap.find(B.at(i)) == bMap.end()) {
            bMap[B.at(i)] = {i};
        } else {
            bMap.at(B.at(i)).push_back(i);
        }

        end = max(end, A.at(i));
    }

    vector<long long> ans(M + 1, 0);
    while (true) {
        ans.at(end - start + 1)++;
        if (M - start + 2 <= M) {
            ans.at(M - start + 2)--;
        }

        auto bFound = bMap.find(start);
        if (bFound != bMap.end()) {
            break;
        }

        auto aFound = aMap.find(start);
        if (aFound != aMap.end()) {
            for (auto a: aMap.at(start)) {
                end = max(end, B[a]);
            }
        }
        start++;
    }

    for (int i = 1; i <= M; i++) {
        ans[i] += ans[i - 1];
        if (i != 1) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
}
