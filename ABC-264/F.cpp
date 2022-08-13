#include <bits/stdc++.h>

using namespace std;

long long w_solve(int H, int W, vector<long long> &R, vector<long long> &C, vector<vector<bool>> &A) {
    vector<vector<vector<vector<long long>>>> w_dp(
            H + 1,
            vector<vector<vector<long long>>>(
                    W + 1,
                    vector<vector<long long>>(
                            2,
                            vector<long long>(2, 1e18))));
    if (A.at(1).at(1)) {
        w_dp.at(1).at(1).at(1).at(0) = R.at(1);
        w_dp.at(1).at(1).at(0).at(1) = C.at(1);
    } else {
        w_dp.at(1).at(1).at(0).at(0) = 0;
        w_dp.at(1).at(1).at(1).at(1) = R.at(1) + C.at(1);
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (i < H) {
                if (A.at(i).at(j) && A.at(i + 1).at(j)) {
                    w_dp.at(i + 1).at(j).at(1).at(0) = min(w_dp.at(i + 1).at(j).at(1).at(0),
                                                           w_dp.at(i).at(j).at(1).at(0) + R.at(i + 1));
                    w_dp.at(i + 1).at(j).at(0).at(1) = min(w_dp.at(i + 1).at(j).at(0).at(1),
                                                           w_dp.at(i).at(j).at(0).at(1));
                } else if (!A.at(i).at(j) && A.at(i + 1).at(j)) {
                    w_dp.at(i + 1).at(j).at(1).at(0) = min(w_dp.at(i + 1).at(j).at(1).at(0),
                                                           w_dp.at(i).at(j).at(0).at(0) + R.at(i + 1));
                    w_dp.at(i + 1).at(j).at(0).at(1) = min(w_dp.at(i + 1).at(j).at(0).at(1),
                                                           w_dp.at(i).at(j).at(1).at(1));
                } else if (A.at(i).at(j) && !A.at(i + 1).at(j)) {
                    w_dp.at(i + 1).at(j).at(0).at(0) = min(w_dp.at(i + 1).at(j).at(0).at(0),
                                                           w_dp.at(i).at(j).at(1).at(0));
                    w_dp.at(i + 1).at(j).at(1).at(1) = min(w_dp.at(i + 1).at(j).at(1).at(1),
                                                           w_dp.at(i).at(j).at(0).at(1) + R.at(i + 1));
                } else {
                    w_dp.at(i + 1).at(j).at(0).at(0) = min(w_dp.at(i + 1).at(j).at(0).at(0),
                                                           w_dp.at(i).at(j).at(0).at(0));
                    w_dp.at(i + 1).at(j).at(1).at(1) = min(w_dp.at(i + 1).at(j).at(1).at(1),
                                                           w_dp.at(i).at(j).at(1).at(1) + R.at(i + 1));
                }
            }
            if (j < W) {
                if (A.at(i).at(j) && A.at(i).at(j + 1)) {
                    w_dp.at(i).at(j + 1).at(1).at(0) = min(w_dp.at(i).at(j + 1).at(1).at(0),
                                                           w_dp.at(i).at(j).at(1).at(0));
                    w_dp.at(i).at(j + 1).at(0).at(1) = min(w_dp.at(i).at(j + 1).at(0).at(1),
                                                           w_dp.at(i).at(j).at(0).at(1) + C.at(j + 1));
                } else if (!A.at(i).at(j) && A.at(i).at(j + 1)) {
                    w_dp.at(i).at(j + 1).at(1).at(0) = min(w_dp.at(i).at(j + 1).at(1).at(0),
                                                           w_dp.at(i).at(j).at(1).at(1));
                    w_dp.at(i).at(j + 1).at(0).at(1) = min(w_dp.at(i).at(j + 1).at(0).at(1),
                                                           w_dp.at(i).at(j).at(0).at(0) + C.at(j + 1));
                } else if (A.at(i).at(j) && !A.at(i).at(j + 1)) {
                    w_dp.at(i).at(j + 1).at(0).at(0) = min(w_dp.at(i).at(j + 1).at(0).at(0),
                                                           w_dp.at(i).at(j).at(0).at(1));
                    w_dp.at(i).at(j + 1).at(1).at(1) = min(w_dp.at(i).at(j + 1).at(1).at(1),
                                                           w_dp.at(i).at(j).at(1).at(0) + C.at(j + 1));
                } else {
                    w_dp.at(i).at(j + 1).at(0).at(0) = min(w_dp.at(i).at(j + 1).at(0).at(0),
                                                           w_dp.at(i).at(j).at(0).at(0));
                    w_dp.at(i).at(j + 1).at(1).at(1) = min(w_dp.at(i).at(j + 1).at(1).at(1),
                                                           w_dp.at(i).at(j).at(1).at(1) + C.at(j + 1));
                }
            }
        }
    }

    long long ans = 1e18;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, w_dp.at(H).at(W).at(i).at(j));
        }
    }
    return ans;
}

long long b_solve(int H, int W, vector<long long> &R, vector<long long> &C, vector<vector<bool>> &A) {
    vector<vector<vector<vector<long long>>>> b_dp(
            H + 1,
            vector<vector<vector<long long>>>(
                    W + 1,
                    vector<vector<long long>>(
                            2,
                            vector<long long>(2, 1e18))));
    if (!A.at(1).at(1)) {
        b_dp.at(1).at(1).at(1).at(0) = R.at(1);
        b_dp.at(1).at(1).at(0).at(1) = C.at(1);
    } else {
        b_dp.at(1).at(1).at(0).at(0) = 0;
        b_dp.at(1).at(1).at(1).at(1) = R.at(1) + C.at(1);
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (i < H) {
                if (!A.at(i).at(j) && !A.at(i + 1).at(j)) {
                    b_dp.at(i + 1).at(j).at(1).at(0) = min(b_dp.at(i + 1).at(j).at(1).at(0),
                                                           b_dp.at(i).at(j).at(1).at(0) + R.at(i + 1));
                    b_dp.at(i + 1).at(j).at(0).at(1) = min(b_dp.at(i + 1).at(j).at(0).at(1),
                                                           b_dp.at(i).at(j).at(0).at(1));
                } else if (A.at(i).at(j) && !A.at(i + 1).at(j)) {
                    b_dp.at(i + 1).at(j).at(1).at(0) = min(b_dp.at(i + 1).at(j).at(1).at(0),
                                                           b_dp.at(i).at(j).at(0).at(0) + R.at(i + 1));
                    b_dp.at(i + 1).at(j).at(0).at(1) = min(b_dp.at(i + 1).at(j).at(0).at(1),
                                                           b_dp.at(i).at(j).at(1).at(1));
                } else if (!A.at(i).at(j) && A.at(i + 1).at(j)) {
                    b_dp.at(i + 1).at(j).at(0).at(0) = min(b_dp.at(i + 1).at(j).at(0).at(0),
                                                           b_dp.at(i).at(j).at(1).at(0));
                    b_dp.at(i + 1).at(j).at(1).at(1) = min(b_dp.at(i + 1).at(j).at(1).at(1),
                                                           b_dp.at(i).at(j).at(0).at(1) + R.at(i + 1));
                } else {
                    b_dp.at(i + 1).at(j).at(0).at(0) = min(b_dp.at(i + 1).at(j).at(0).at(0),
                                                           b_dp.at(i).at(j).at(0).at(0));
                    b_dp.at(i + 1).at(j).at(1).at(1) = min(b_dp.at(i + 1).at(j).at(1).at(1),
                                                           b_dp.at(i).at(j).at(1).at(1) + R.at(i + 1));
                }
            }
            if (j < W) {
                if (!A.at(i).at(j) && !A.at(i).at(j + 1)) {
                    b_dp.at(i).at(j + 1).at(1).at(0) = min(b_dp.at(i).at(j + 1).at(1).at(0),
                                                           b_dp.at(i).at(j).at(1).at(0));
                    b_dp.at(i).at(j + 1).at(0).at(1) = min(b_dp.at(i).at(j + 1).at(0).at(1),
                                                           b_dp.at(i).at(j).at(0).at(1) + C.at(j + 1));
                } else if (A.at(i).at(j) && !A.at(i).at(j + 1)) {
                    b_dp.at(i).at(j + 1).at(1).at(0) = min(b_dp.at(i).at(j + 1).at(1).at(0),
                                                           b_dp.at(i).at(j).at(1).at(1));
                    b_dp.at(i).at(j + 1).at(0).at(1) = min(b_dp.at(i).at(j + 1).at(0).at(1),
                                                           b_dp.at(i).at(j).at(0).at(0) + C.at(j + 1));
                } else if (!A.at(i).at(j) && A.at(i).at(j + 1)) {
                    b_dp.at(i).at(j + 1).at(0).at(0) = min(b_dp.at(i).at(j + 1).at(0).at(0),
                                                           b_dp.at(i).at(j).at(0).at(1));
                    b_dp.at(i).at(j + 1).at(1).at(1) = min(b_dp.at(i).at(j + 1).at(1).at(1),
                                                           b_dp.at(i).at(j).at(1).at(0) + C.at(j + 1));
                } else {
                    b_dp.at(i).at(j + 1).at(0).at(0) = min(b_dp.at(i).at(j + 1).at(0).at(0),
                                                           b_dp.at(i).at(j).at(0).at(0));
                    b_dp.at(i).at(j + 1).at(1).at(1) = min(b_dp.at(i).at(j + 1).at(1).at(1),
                                                           b_dp.at(i).at(j).at(1).at(1) + C.at(j + 1));
                }
            }
        }
    }

    long long ans = 1e18;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, b_dp.at(H).at(W).at(i).at(j));
        }
    }
    return ans;
}

int main() {
    int H, W;
    cin >> H >> W;

    vector<long long> R(H + 1);
    for (int i = 1; i <= H; i++) {
        cin >> R.at(i);
    }

    vector<long long> C(W + 1);
    for (int i = 1; i <= W; i++) {
        cin >> C.at(i);
    }

    vector<vector<bool>> A(H + 1, vector<bool>(W + 1));
    for (int i = 1; i <= H; i++) {
        string ai;
        cin >> ai;
        for (int j = 1; j <= W; j++) {
            A.at(i).at(j) = ai.at(j - 1) == '1';
            // cout << "A.at(" << i << ").at(" << j << "): " << A.at(i).at(j) << endl;
        }
    }

    long long w_ans = w_solve(H, W, R, C, A);
    long long b_ans = b_solve(H, W, R, C, A);

    cout << min(w_ans, b_ans) << endl;
}
