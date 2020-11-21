import unittest

import myadd


class TestAddFunction(unittest.TestCase):

    def test_add(self):
        self.assertEqual(myadd.add(3, 2), 5)


if __name__ == '__main__':
    unittest.main()
