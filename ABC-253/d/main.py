import math
import sys


def total(n):
    if n % 2 == 0:
        return (n + 1) * int(n / 2)
    else:
        return int((n + 1) / 2) * n


def main():
    readline = sys.stdin.readline

    n, a, b = map(int, readline().split())

    total_n = total(n)

    count_a = math.floor(n / a)
    total_a = a * total(count_a)

    count_b = math.floor(n / b)
    total_b = b * total(count_b)

    gcd = math.gcd(a, b)
    lcm = int((a * b) / gcd)

    count_lcm = math.floor(n / lcm)
    total_lcm = lcm * total(count_lcm)

    ans = total_n - total_a - total_b + total_lcm
    print(ans)


if __name__ == '__main__':
    main()
