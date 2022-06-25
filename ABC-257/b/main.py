import sys


def main():
    readline = sys.stdin.readline

    n, k, q = map(int, readline().split())
    a = list(map(int, readline().split()))
    l = list(map(int, readline().split()))

    for i in range(q):
        index = l[i] - 1
        if index == len(a) - 1 and a[index] == n:
            continue
        if index < len(a) - 1 and a[index] + 1 == a[index + 1]:
            continue
        a[index] += 1

    print(" ".join(map(str, a)))


if __name__ == '__main__':
    main()
