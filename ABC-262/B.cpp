#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, map<int, bool>> connected;

    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        connected[U][V] = true;
        connected[V][U] = true;
    }

    int ans = 0;
    for (int a = 1; a <= N; a++) {
        for (int b = a + 1; b <= N; b++) {
            for (int c = b + 1; c <= N; c++) {
                if (connected[a][b] && connected[b][c] && connected[c][a]) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
