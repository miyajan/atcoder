import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())
    a = list(map(int, readline().split()))

    m = [False, False, False, False]
    ans = 0
    for ai in a:
        m[0] = True
        for j in reversed(range(4)):
            if m[j]:
                if j + ai >= 4:
                    ans += 1
                else:
                    m[j + ai] = True
                m[j] = False

    print(ans)


if __name__ == '__main__':
    main()
