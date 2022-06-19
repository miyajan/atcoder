import math
import sys


def main():
    readline = sys.stdin.readline

    n, l = map(int, readline().split())
    k = int(readline())
    a = list(map(int, readline().split()))

    left = 0
    right = l + 1
    mid = math.floor((left + right) / 2)

    while right - left > 1:
        count = 0
        length = 0
        for i in range(n + 1):
            if i == 0:
                length += a[i]
            elif i == n:
                length += l - a[n - 1]
            else:
                length += a[i] - a[i - 1]
            if length >= mid:
                count += 1
                length = 0

        if count > k:
            left = mid
        else:
            right = mid
        mid = math.floor((left + right) / 2)

    print(left)


if __name__ == '__main__':
    main()
