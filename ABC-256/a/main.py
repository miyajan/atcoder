import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())

    ans = 2**n
    print(ans)


if __name__ == '__main__':
    main()
