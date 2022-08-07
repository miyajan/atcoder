#include <bits/stdc++.h>

using namespace std;

long long N, sx, sy, tx, ty;

struct UnionFind {
    vector<long long> par;

    UnionFind(long long n) : par(n) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) {
            return;
        }
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    cin >> N >> sx >> sy >> tx >> ty;

    long long x[N];
    long long y[N];
    long long r[N];
    vector<long long> sBelongsTo;
    vector<long long> tBelongsTo;

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
        long long dsx = x[i] - sx;
        long long dsy = y[i] - sy;
        if (dsx * dsx + dsy * dsy == r[i] * r[i]) {
            sBelongsTo.push_back(i);
        }
        long long dtx = x[i] - tx;
        long long dty = y[i] - ty;
        if (dtx * dtx + dty * dty == r[i] * r[i]) {
            tBelongsTo.push_back(i);
        }
    }

    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            long long pDist = dx * dx + dy * dy;
            if (pDist <= (r[i] + r[j]) * (r[i] + r[j]) && pDist >= (r[i] - r[j]) * (r[i] - r[j])) {
                uf.unite(i, j);
            }
        }
    }

    for (int i = 0; i < sBelongsTo.size(); i++) {
        for (int j = 0; j < tBelongsTo.size(); j++) {
            if (uf.same(sBelongsTo[i], tBelongsTo[j])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
