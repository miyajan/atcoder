import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())
    a = []
    for i in range(n):
        a.append([])
        for j in range(i + 1):
            if j == 0:
                a[i].append(1)
            elif j == i:
                a[i].append(1)
            else:
                a[i].append(a[i - 1][j - 1] + a[i - 1][j])
        print(" ".join(str(x) for x in a[i]))


if __name__ == '__main__':
    main()
