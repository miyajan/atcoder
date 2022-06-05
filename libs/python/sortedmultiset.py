# Thanks to https://github.com/tatyam-prime/SortedSet.
import math
from bisect import bisect_right, bisect_left, insort
from typing import Generic, Iterator, List, TypeVar, Union

T = TypeVar('T')


class SortedMultiSet(Generic[T]):
    BUCKET_RATIO = 50
    REBUILD_RATIO = 170

    def __init__(self) -> None:
        self._size = 0
        self._buckets = [[]]

    def _rebuild(self) -> None:
        sorted_list = list(self)
        bucket_size = int(math.ceil(math.sqrt(self._size / self.BUCKET_RATIO)))
        self._buckets = []
        for i in range(bucket_size):
            start = int((self._size / bucket_size) * i)
            end = int((self._size / bucket_size) * (i + 1))
            self._buckets.append(sorted_list[start:end])

    def __iter__(self) -> Iterator[T]:
        for bucket in self._buckets:
            for x in bucket:
                yield x

    def __reversed__(self) -> Iterator[T]:
        for bucket in reversed(self._buckets):
            for x in reversed(bucket):
                yield x

    def __len__(self) -> int:
        return self._size

    def __repr__(self) -> str:
        return "SortedMultiSet" + str(self._buckets)

    def __str__(self) -> str:
        return str(list(self))

    def __getitem__(self, x: int) -> T:
        """Returns the x-th element, or raises Index Error if it doesn't exist."""
        if x < 0:
            x += self._size
        if x < 0:
            raise IndexError
        for bucket in self._buckets:
            if x < len(bucket):
                return bucket[x]
            x -= len(bucket)
        raise IndexError

    def _find_bucket(self, x: T) -> List[T]:
        """Finds the bucket which should contain x."""
        for bucket in self._buckets:
            if x <= bucket[-1]:
                return bucket
        return self._buckets[-1]

    def __contains__(self, x: T) -> bool:
        if self._size == 0:
            return False
        bucket = self._find_bucket(x)
        i = bisect_left(bucket, x)
        return i != len(bucket) and bucket[i] == x

    def add(self, x: T) -> None:
        """Adds an element."""
        if self._size == 0:
            self._buckets = [[x]]
            self._size = 1
            return
        bucket = self._find_bucket(x)
        insort(bucket, x)
        self._size += 1
        if len(bucket) > len(self._buckets) * self.REBUILD_RATIO:
            self._rebuild()

    def remove(self, x: T) -> bool:
        """Removes an element. Returns False if it doesn't exist."""
        if self._size == 0:
            return False
        bucket = self._find_bucket(x)
        i = bisect_left(bucket, x)
        if i == len(bucket) or bucket[i] != x:
            return False
        bucket.pop(i)
        self._size -= 1
        if len(bucket) == 0:
            self._rebuild()
        return True

    def find_max_less_than(self, x: T) -> Union[T, None]:
        """Finds the max element < x, or None if it doesn't exist."""
        for bucket in reversed(self._buckets):
            if bucket[0] < x:
                return bucket[bisect_left(bucket, x) - 1]
        return None

    def find_max_less_than_or_equal_to(self, x: T) -> Union[T, None]:
        """Finds the max element <= x, or None if it doesn't exist."""
        for bucket in reversed(self._buckets):
            if bucket[0] <= x:
                return bucket[bisect_right(bucket, x) - 1]
        return None

    def find_min_greater_than(self, x: T) -> Union[T, None]:
        """Finds the min element > x, or None if it doesn't exists."""
        for bucket in self._buckets:
            if bucket[-1] > x:
                return bucket[bisect_right(bucket, x)]

    def find_min_greater_than_or_equal_to(self, x: T) -> Union[T, None]:
        """Finds the min element >= x, or None if it doesn't exists."""
        for bucket in self._buckets:
            if bucket[-1] >= x:
                return bucket[bisect_left(bucket, x)]

    def count(self, x: T) -> int:
        """Count the number of elements = x."""
        return self.count_less_than_or_equal_to(x) - self.count_less_than(x)

    def count_less_than(self, x: T) -> int:
        """Count the number of elements < x."""
        ans = 0
        for bucket in self._buckets:
            if bucket[-1] >= x:
                return ans + bisect_left(bucket, x)
            ans += len(bucket)
        return ans

    def count_less_than_or_equal_to(self, x: T) -> int:
        """Count the number of elements <= x."""
        ans = 0
        for bucket in self._buckets:
            if bucket[-1] > x:
                return ans + bisect_right(bucket, x)
            ans += len(bucket)
        return ans
