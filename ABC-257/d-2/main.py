"""
O(N**3)
Python 3.8.2: AC (2955 ms)
PyPy3 (7.3.0): AC (222 ms)
"""
import math
import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())

    x = []
    y = []
    p = []
    for i in range(n):
        xi, yi, pi = map(int, readline().split())
        x.append(xi)
        y.append(yi)
        p.append(pi)

    def calc_required_training(i, j):
        return math.ceil((abs(x[i] - x[j]) + abs(y[i] - y[j])) / p[i])

    d = []
    for i in range(n):
        di = []
        for j in range(n):
            di.append(calc_required_training(i, j))
        d.append(di)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]))

    ans = 4 * 10 ** 9
    for i in range(n):
        ma = 0
        for j in range(n):
            if d[i][j] > ma:
                ma = d[i][j]
        if ma < ans:
            ans = ma

    print(ans)


if __name__ == '__main__':
    main()
