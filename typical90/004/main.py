import sys


def main():
    readline = sys.stdin.readline

    h, w = map(int, readline().split())

    total_rows = [0] * h
    total_columns = [0] * w
    a = []
    for i in range(h):
        ai = list(map(int, readline().split()))
        a.append([])
        for j in range(w):
            a[i].append(ai[j])
            total_rows[i] += ai[j]
            total_columns[j] += ai[j]

    for i in range(h):
        bi = []
        for j in range(w):
            bi.append(str(total_rows[i] + total_columns[j] - a[i][j]))
        print(" ".join(bi))


if __name__ == '__main__':
    main()
