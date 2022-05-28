import heapq
import sys


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


def main():
    readline = sys.stdin.readline

    q = int(readline())
    min_max_heap = MinMaxHeap()

    for i in range(0, q):
        tokens = readline().split()
        op = int(tokens[0])
        if op == 1:
            x = int(tokens[1])
            min_max_heap.insert(x)
        elif op == 2:
            x = int(tokens[1])
            c = int(tokens[2])
            for _ in range(min(c, min_max_heap.count(x))):
                min_max_heap.erase(x)
        elif op == 3:
            print(min_max_heap.get_max() - min_max_heap.get_min())


# def main():
#     readline = sys.stdin.readline
#
#     q = int(readline())
#     min_heap = []
#     max_heap = []
#     count = {}
#
#     for i in range(0, q):
#         tokens = readline().split()
#         op = int(tokens[0])
#         if op == 1:
#             x = int(tokens[1])
#             heapq.heappush(min_heap, x)
#             heapq.heappush(max_heap, -x)
#             if x in count:
#                 count[x] += 1
#             else:
#                 count[x] = 1
#         elif op == 2:
#             x = int(tokens[1])
#             c = int(tokens[2])
#             if x in count:
#                 count[x] = max(0, count[x] - c)
#         elif op == 3:
#             while min_heap[0] in count and count[min_heap[0]] == 0:
#                 heapq.heappop(min_heap)
#             while -max_heap[0] in count and count[-max_heap[0]] == 0:
#                 heapq.heappop(max_heap)
#             print(-max_heap[0] - min_heap[0])


if __name__ == '__main__':
    main()
