import sys


def main():
    readline = sys.stdin.readline

    h, w = map(int, readline().split())
    s = []
    ax, ay, bx, by = 0, 0, 0, 0
    for i in range(0, h):
        sl = readline()
        for j in range(0, w):
            if sl[j] == 'o':
                if ax == 0:
                    ax, ay = j+1, i+1
                else:
                    bx, by = j+1, i+1

    ans = abs(ax-bx) + abs(ay-by)
    print(ans)


if __name__ == '__main__':
    main()
