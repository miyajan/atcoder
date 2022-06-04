import math
import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())

    a = []
    b = []
    squares = []
    x = 0
    for i in range(1, n + 1):
        if math.sqrt(i).is_integer():
            x += 1
            squares.append(i)
        a.append(x)
        b.append(i)

    for square in squares:
        if square == 1:
            continue
        for j in range(int(n / square)):
            b[square * (j + 1) - 1] = j + 1

    ans = 0
    for i in range(1, n + 1):
        m = n // b[i - 1]
        ans += a[m - 1]

    print(ans)


if __name__ == '__main__':
    main()
