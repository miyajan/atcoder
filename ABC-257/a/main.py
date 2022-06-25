import sys


def main():
    readline = sys.stdin.readline

    n, x = map(int, readline().split())

    s = 'A'
    o = ord(s)
    c = chr(o + int((x-1) / n))

    print(c)


if __name__ == '__main__':
    main()
