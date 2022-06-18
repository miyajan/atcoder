import heapq
import sys


def main():
    readline = sys.stdin.readline

    n = int(readline())

    l = []
    r = []
    for i in range(n):
        li, ri = map(int, readline().split())
        heapq.heappush(l, li)
        heapq.heappush(r, ri)

    count = 0
    start = None
    while len(l) > 0 or len(r) > 0:
        if start is None:
            start = heapq.heappop(l)
            count += 1
        elif len(l) > 0 and l[0] <= r[0]:
            heapq.heappop(l)
            count += 1
        else:
            end = heapq.heappop(r)
            count -= 1
            if count == 0:
                print("{} {}".format(start, end))
                start = None


if __name__ == '__main__':
    main()
