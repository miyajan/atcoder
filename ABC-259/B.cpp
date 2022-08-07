#include <bits/stdc++.h>

using namespace std;

long double a, b, d;

int main() {
    cin >> a >> b >> d;

    cout << fixed << setprecision(10) << a * cos(d * M_PI / 180) + b * (-sin(d * M_PI / 180)) << " "
         << a * sin(d * M_PI / 180) + b * cos(d * M_PI / 180) << endl;
}
