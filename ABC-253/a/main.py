import sys


def main():
    readline = sys.stdin.readline

    a, b, c = map(int, readline().split())
    if (a < b < c) or (c < b < a) or (a == b) or (c == b):
        ans = "Yes"
    else:
        ans = "No"

    print(ans)


if __name__ == '__main__':
    main()
