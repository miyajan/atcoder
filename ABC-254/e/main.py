import sys


def main():
    readline = sys.stdin.readline

    n, m = map(int, readline().split())

    conns = {}
    for i in range(n):
        conns[i + 1] = set()

    for i in range(m):
        ai, bi = map(int, readline().split())
        conns[ai].add(bi)
        conns[bi].add(ai)

    q = int(readline())
    for i in range(q):
        xi, ki = map(int, readline().split())
        points = {xi}
        current_points = {xi}
        while ki > 0:
            next_points = set()
            for p in current_points:
                for neighbor_p in conns[p]:
                    if neighbor_p in points:
                        continue
                    points.add(neighbor_p)
                    next_points.add(neighbor_p)
            ki -= 1
            current_points = next_points
        ans = 0
        for p in points:
            ans += p
        print(ans)


if __name__ == '__main__':
    main()
