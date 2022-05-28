import heapq


class MinMaxHeap:
    def __init__(self):
        self._min_heap = []
        self._max_heap = []
        self._count = {}

    # O(logN)
    def insert(self, x):
        heapq.heappush(self._min_heap, x)
        heapq.heappush(self._max_heap, -x)
        if x in self._count:
            self._count[x] += 1
        else:
            self._count[x] = 1

    # O(1)
    def erase(self, x):
        if x in self._count:
            self._count[x] -= 1
            if self._count[x] == 0:
                del self._count[x]
            return True
        return False

    # O(logN)
    def get_min(self):
        while self._min_heap[0] not in self._count:
            heapq.heappop(self._min_heap)
        return self._min_heap[0]

    # O(logN)
    def get_max(self):
        while -self._max_heap[0] not in self._count:
            heapq.heappop(self._max_heap)
        return -self._max_heap[0]

    # O(1)
    def count(self, x):
        if x in self._count:
            return self._count[x]
        return 0
