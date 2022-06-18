import sys


class UnionFind:
    def __init__(self, n):
        self._size = n
        self._parent_or_rank = [-1] * n

    def union(self, x, y) -> int:
        """0 <= x,y < self._size"""
        parent_x = self.find(x)
        parent_y = self.find(y)
        if parent_x == parent_y:
            return parent_x
        if -self._parent_or_rank[parent_x] < -self._parent_or_rank[parent_y]:
            parent_x, parent_y = parent_y, parent_x
        self._parent_or_rank[parent_x] += self._parent_or_rank[parent_y]
        self._parent_or_rank[parent_y] = parent_x
        return parent_x

    def find(self, x) -> int:
        """0 <= index < self._size"""
        if self._parent_or_rank[x] < 0:
            return x
        self._parent_or_rank[x] = self.find(self._parent_or_rank[x])
        return self._parent_or_rank[x]


def main():
    readline = sys.stdin.readline

    n = int(readline())
    x = list(map(int, readline().split()))
    c = list(map(int, readline().split()))

    uf = UnionFind(n)
    ans = 0
    for i in range(n):
        if uf.find(i) == uf.find(x[i] - 1):
            current = x[i] - 1
            min_c = c[i]
            while current != i:
                min_c = min(min_c, c[current])
                current = x[current] - 1
            ans += min_c
            continue

        uf.union(i, x[i] - 1)

    print(ans)


if __name__ == '__main__':
    main()
