import sys


def main():
    readline = sys.stdin.readline

    a = int(readline())
    b, c = map(int, readline().split())
    s = readline()[:-1]

    ans = "{} {}".format(a + b + c, s)
    print(ans)


if __name__ == '__main__':
    main()
