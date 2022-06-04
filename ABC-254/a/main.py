import sys


def main():
    readline = sys.stdin.readline

    n = readline()[:-1]

    ans = n[1:]
    print(ans)


if __name__ == '__main__':
    main()
