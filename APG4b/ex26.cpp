#include <bits/stdc++.h>

using namespace std;

int parse_int_or_variable(map<string, int> &ints) {
    string str;
    cin >> str;
    if (all_of(str.begin(), str.end(), ::isdigit)) {
        return stoi(str);
    }
    return ints.at(str);
}

int parse_int_formula(map<string, int> &ints) {
    int int_value = parse_int_or_variable(ints);
    string opOrEnd;
    cin >> opOrEnd;
    while (opOrEnd != ";") {
        int second_int = parse_int_or_variable(ints);
        if (opOrEnd == "+") {
            int_value += second_int;
        } else {
            int_value -= second_int;
        }
        cin >> opOrEnd;
    }
    return int_value;
}

vector<int> parse_vec_or_variable(map<string, int> &ints, map<string, vector<int>> &vecs) {
    string bracket_or_var;
    cin >> bracket_or_var;
    if (bracket_or_var == "[") {
        vector<int> ret = {};
        ret.push_back(parse_int_or_variable(ints));
        string comma_or_end;
        cin >> comma_or_end;
        while (comma_or_end == ",") {
            ret.push_back(parse_int_or_variable(ints));
            cin >> comma_or_end;
        }
        return ret;
    }
    return vecs[bracket_or_var];
}

vector<int> parse_vec_formula(map<string, int> &ints, map<string, vector<int>> &vecs) {
    vector<int> vec = parse_vec_or_variable(ints, vecs);
    string opOrEnd;
    cin >> opOrEnd;
    while (opOrEnd != ";") {
        vector<int> second_vec = parse_vec_or_variable(ints, vecs);
        for (int i = 0; i < vec.size(); i++) {
            if (opOrEnd == "+") {
                vec.at(i) += second_vec.at(i);
            } else {
                vec.at(i) -= second_vec.at(i);
            }
        }
        cin >> opOrEnd;
    }
    return vec;
}

int main() {
    int N;
    cin >> N;
    map<string, int> ints;
    map<string, vector<int>> vecs;
    for (int i = 0; i < N; i++) {
        string op;
        cin >> op;
        if (op == "int") {
            string int_name;
            cin >> int_name;
            string equal;
            cin >> equal;
            ints[int_name] = parse_int_formula(ints);
        } else if (op == "print_int") {
            cout << parse_int_formula(ints) << endl;
        } else if (op == "vec") {
            string vec_name;
            cin >> vec_name;
            string equal;
            cin >> equal;
            vecs[vec_name] = parse_vec_formula(ints, vecs);
        } else if (op == "print_vec") {
            vector<int> vec = parse_vec_formula(ints, vecs);
            cout << "[ ";
            for (auto value : vec) {
                cout << value << " ";
            }
            cout << "]" << endl;
        }
    }
}
