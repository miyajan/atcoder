import sys


def compare(a, b):
    readline = sys.stdin.readline

    print('? {} {}'.format(a, b), flush=True)

    ans = readline()[:-1]
    return ans == "<"


def sort2(l):
    if not compare(l[0], l[1]):
        l[0], l[1] = l[1], l[0]
    return l


def sort5(l):
    l1 = sort2(l[0:2])
    l2 = sort2(l[2:4])
    e = l[4]

    if not compare(l1[0], l2[0]):
        l1, l2 = l2, l1

    # l1[0] < l2[0] < l2[1]
    if not compare(l2[0], e):
        # e < l2[0] < l2[1]
        if not compare(l1[0], e):
            # e < l1[0] < l2[0] < l2[1]
            if not compare(l2[0], l1[1]):
                return [e, l1[0], l1[1], l2[0], l2[1]]
            if not compare(l2[1], l1[1]):
                return [e, l1[0], l2[0], l1[1], l2[1]]
            return [e, l1[0], l2[0], l2[1], l1[1]]

        # l1[0] < e < l2[0] < l2[1]
        if not compare(l2[0], l1[1]):
            # l1[1] < l2[0]
            if not compare(e, l1[1]):
                return [l1[0], l1[1], e, l2[0], l2[1]]
            return [l1[0], e, l1[1], l2[0], l2[1]]

        # l1[0] < e < l2[0] < l1[1]
        if not compare(l2[1], l1[1]):
            return [l1[0], e, l2[0], l1[1], l2[1]]
        return [l1[0], e, l2[0], l2[1], l1[1]]

    # l1[0] < l2[0] < e
    if not compare(l2[1], e):
        # l1[0] < l2[0] < e < l2[1]
        if not compare(e, l1[1]):
            # l1[1] < e
            if not compare(l2[0], l1[1]):
                return [l1[0], l1[1], l2[0], e, l2[1]]
            return [l1[0], l2[0], l1[1], e, l2[1]]
        # l1[0] < l2[0] < e < l1[1]
        if not compare(l2[1], l1[1]):
            return [l1[0], l2[0], e, l1[1], l2[1]]
        return [l1[0], l2[0], e, l2[1], l1[1]]

    # l1[0] < l2[0] < l2[1] < e
    if not compare(l2[1], l1[1]):
        if not compare(l2[0], l1[1]):
            return [l1[0], l1[1], l2[0], l2[1], e]
        return [l1[0], l2[0], l1[1], l2[1], e]
    if not compare(e, l1[1]):
        return [l1[0], l2[0], l2[1], l1[1], e]
    return [l1[0], l2[0], l2[1], e, l1[1]]


def sort(l):
    if len(l) == 2:
        return sort2(l)

    if len(l) == 5:
        return sort5(l)


def main():
    readline = sys.stdin.readline

    n, q = map(int, readline().split())
    l = list(chr(ord('A') + x) for x in range(0, n))

    ans = l
    print(ans)


if __name__ == '__main__':
    main()
