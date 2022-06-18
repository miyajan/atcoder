# Thanks to https://github.com/atcoder/ac-library/blob/master/atcoder/dsu.hpp.
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
