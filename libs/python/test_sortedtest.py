import unittest

from libs.python.sortedset import SortedSet


class SortedSetTests(unittest.TestCase):
    def test_add_10000_times(self):
        # setup
        sut = SortedSet()

        # exercise
        for i in range(10000):
            sut.add(i)

        # verify
        self.assertEqual(len(sut), 10000)
        self.assertEqual(sut[-1], 9999)
        self.assertEqual(sut[0], 0)
        self.assertEqual(sut[9999], 9999)

    def test_remove_when_x_exists(self):
        # setup
        sut = SortedSet()
        for i in range(10000):
            sut.add(i)

        # exercise
        ret = sut.remove(5000)

        # verify
        self.assertEqual(ret, True)
        self.assertEqual(len(sut), 9999)
        self.assertEqual(sut[0], 0)
        self.assertEqual(sut[5000], 5001)
        self.assertEqual(sut[9998], 9999)

    def test_remove_when_x_not_exist(self):
        # setup
        sut = SortedSet()
        for i in range(10000):
            sut.add(i)

        # exercise
        ret = sut.remove(10000)

        # verify
        self.assertEqual(ret, False)
        self.assertEqual(len(sut), 10000)
        self.assertEqual(sut[0], 0)
        self.assertEqual(sut[9999], 9999)

    def test_find_max_less_than(self):
        # setup
        sut = SortedSet()
        for i in range(5000):
            sut.add(i * 2)

        for x, expected in [(0, None), (1, 0), (2, 0), (3, 2), (9998, 9996), (10000, 9998)]:
            with self.subTest():
                # exercise
                actual = sut.find_max_less_than(x)

                # verify
                self.assertEqual(actual, expected)

    def test_find_max_less_than_or_equal_to(self):
        # setup
        sut = SortedSet()
        for i in range(5000):
            sut.add(i * 2)

        for x, expected in [(-1, None), (0, 0), (1, 0), (2, 2), (9997, 9996), (9998, 9998)]:
            with self.subTest():
                # exercise
                actual = sut.find_max_less_than_or_equal_to(x)

                # verify
                self.assertEqual(actual, expected)

    def test_find_min_greater_than(self):
        # setup
        sut = SortedSet()
        for i in range(5000):
            sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 2), (1, 2), (2, 4), (9997, 9998), (9998, None)]:
            with self.subTest():
                # exercise
                actual = sut.find_min_greater_than(x)

                # verify
                self.assertEqual(actual, expected)

    def test_find_min_greater_than_or_equal_to(self):
        # setup
        sut = SortedSet()
        for i in range(5000):
            sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 0), (1, 2), (2, 2), (9998, 9998), (9999, None)]:
            with self.subTest():
                # exercise
                actual = sut.find_min_greater_than_or_equal_to(x)

                # verify
                self.assertEqual(actual, expected)

    def test_count_less_than(self):
        # setup
        sut = SortedSet()
        for i in range(5000):
            sut.add(i * 2)

        for x, expected in [(0, 0), (1, 1), (2, 1), (3, 2), (9998, 4999), (9999, 5000)]:
            with self.subTest():
                # exercise
                actual = sut.count_less_than(x)

                # verify
                self.assertEqual(actual, expected)

    def test_count_less_than_or_equal_to(self):
        # setup
        sut = SortedSet()
        for i in range(5000):
            sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 1), (1, 1), (2, 2), (9997, 4999), (9998, 5000)]:
            with self.subTest():
                # exercise
                actual = sut.count_less_than_or_equal_to(x)

                # verify
                self.assertEqual(actual, expected)
