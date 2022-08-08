#include <bits/stdc++.h>

using namespace std;

void print_all(int N, int M, vector<int> &current, int pos) {
    if (current.size() == N) {
        for (int i = 0; i < N; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << current.at(i);
        }
        cout << endl;
    } else {
        for (int i = pos; i <= M - (N - current.size()) + 1; i++) {
//            cout << "current: [";
//            for (int j = 0; j < current.size(); j++) {
//                if (j > 0) {
//                    cout << " ";
//                }
//                cout << current.at(j);
//            }
//            cout << "]" << endl;

            current.push_back(i);
            print_all(N, M, current, i + 1);
            current.pop_back();
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> current;
    print_all(N, M, current, 1);
}
