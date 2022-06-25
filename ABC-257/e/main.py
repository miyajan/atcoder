"""
O(N)
Python 3.8.2: AC (785 ms)
PyPy3 (7.3.0): TLE
"""
import math
import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())
    c = list(map(int, readline().split()))

    min_c = n
    for i in range(9):
        if c[i] < min_c:
            min_c = c[i]

    num_of_digits = math.floor(n / min_c)

    ans = ""
    for i in range(num_of_digits):
        for j in reversed(range(9)):
            if n >= (num_of_digits - i - 1) * min_c + c[j]:
                ans += str(j + 1)
                n -= c[j]
                break

    print(ans)


if __name__ == '__main__':
    main()
