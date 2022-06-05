import unittest

from sortedmultiset import SortedMultiSet


class SortedMultiSetTests(unittest.TestCase):
    def test_add_10000_times(self):
        # setup
        sut = SortedMultiSet()

        # exercise
        for i in range(1000):
            for j in range(10):
                sut.add(i)

        # verify
        self.assertEqual(len(sut), 10000)
        self.assertEqual(sut[-1], 999)
        self.assertEqual(sut[0], 0)
        self.assertEqual(sut[9999], 999)

    def test_remove_when_x_exists(self):
        # setup
        sut = SortedMultiSet()
        for i in range(1000):
            for j in range(10):
                sut.add(i)

        # exercise
        ret = sut.remove(500)

        # verify
        self.assertEqual(ret, True)
        self.assertEqual(len(sut), 9999)
        self.assertEqual(sut[0], 0)
        self.assertEqual(sut[5000], 500)
        self.assertEqual(sut[5009], 501)
        self.assertEqual(sut[9998], 999)

    def test_remove_when_x_not_exist(self):
        # setup
        sut = SortedMultiSet()
        for i in range(1000):
            for j in range(10):
                sut.add(i)

        # exercise
        ret = sut.remove(10000)

        # verify
        self.assertEqual(ret, False)
        self.assertEqual(len(sut), 10000)
        self.assertEqual(sut[0], 0)
        self.assertEqual(sut[9999], 999)

    def test_find_max_less_than(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(0, None), (1, 0), (2, 0), (3, 2), (998, 996), (999, 998)]:
            with self.subTest():
                # exercise
                actual = sut.find_max_less_than(x)

                # verify
                self.assertEqual(actual, expected)

    def test_find_max_less_than_or_equal_to(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(-1, None), (0, 0), (1, 0), (2, 2), (997, 996), (998, 998)]:
            with self.subTest():
                # exercise
                actual = sut.find_max_less_than_or_equal_to(x)

                # verify
                self.assertEqual(actual, expected)

    def test_find_min_greater_than(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 2), (1, 2), (2, 4), (997, 998), (998, None)]:
            with self.subTest():
                # exercise
                actual = sut.find_min_greater_than(x)

                # verify
                self.assertEqual(actual, expected)

    def test_find_min_greater_than_or_equal_to(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 0), (1, 2), (2, 2), (998, 998), (999, None)]:
            with self.subTest():
                # exercise
                actual = sut.find_min_greater_than_or_equal_to(x)

                # verify
                self.assertEqual(actual, expected)

    def test_count(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 10), (1, 0), (998, 10), (1000, 0)]:
            with self.subTest():
                # exercise
                actual = sut.count(x)

                # verify
                self.assertEqual(actual, expected)

    def test_count_less_than(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(0, 0), (1, 10), (2, 10), (3, 20), (998, 4990), (999, 5000)]:
            with self.subTest():
                # exercise
                actual = sut.count_less_than(x)

                # verify
                self.assertEqual(actual, expected)

    def test_count_less_than_or_equal_to(self):
        # setup
        sut = SortedMultiSet()
        for i in range(500):
            for j in range(10):
                sut.add(i * 2)

        for x, expected in [(-1, 0), (0, 10), (1, 10), (2, 20), (997, 4990), (998, 5000)]:
            with self.subTest():
                # exercise
                actual = sut.count_less_than_or_equal_to(x)

                # verify
                self.assertEqual(actual, expected)
