import sys


def main():
    readline = sys.stdin.readline

    n, b, k = map(int, readline().split())
    c = list(map(int, readline().split()))

    mod = 10 ** 9 + 7

    dp = []
    for i in range(n + 1):
        dp.append([])
        for j in range(b):
            dp[i].append(0)
    dp[0][0] = 1

    for i in range(n):
        for j in range(b):
            for h in range(k):
                nex = (10 * j + c[h]) % b
                dp[i + 1][nex] += dp[i][j]
                dp[i + 1][nex] %= mod

    print(dp[n][0])


if __name__ == '__main__':
    main()
