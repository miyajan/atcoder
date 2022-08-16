#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> lines(M);
    for (int i = 0; i < M; i++) {
        int L, R;
        cin >> L >> R;
        lines.at(i) = {L, R};
    }

    sort(lines.begin(), lines.end());

    atcoder::fenwick_tree<int> ends(N + 1);
    int current_lines_index = 0;
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        vector<int> current_ends;
        while (current_lines_index < lines.size() && lines.at(current_lines_index).first == i) {
//            cout << "start: " << lines.at(current_lines_index).first << ", end: "
//                 << lines.at(current_lines_index).second << endl;
//            cout << "ends: ";
//            for (auto end: ends) {
//                cout << end << ", ";
//            }
//            cout << endl;

            int line_end = lines.at(current_lines_index).second;
            ans += ends.sum(i + 1, line_end);

            current_ends.push_back(line_end);
            current_lines_index++;
        }

        for (auto end: current_ends) {
            ends.add(end, 1);
        }
    }

    cout << ans << endl;
}
