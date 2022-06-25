"""
O(N**3 * log(4*10**9))
Python 3.8.2: TLE
PyPy3 (7.3.0): AC (1846 ms)
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

    left = 0
    right = 4 * (10 ** 9)
    while right - left > 1:
        mid = int((right + left) / 2)
        success = False
        for i in range(n):
            visited = {i}
            currents = [i]
            while len(currents) > 0:
                current = currents.pop()
                for j in range(n):
                    if j in visited:
                        continue
                    if math.ceil((abs(x[current] - x[j]) + abs(y[current] - y[j])) / p[current]) <= mid:
                        visited.add(j)
                        currents.append(j)
            if len(visited) == n:
                success = True
                break
        if success:
            right = mid
        else:
            left = mid

    print(right)


if __name__ == '__main__':
    main()
