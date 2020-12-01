# 三行代码实现快速排序
def qsort(L):
  if len(L) <= 1: return L
  return qsort([lt for lt in L[1:] if lt < L[0]]) + L[0:1] + \
    qsort([ge for ge in L[1:] if ge >= L[0]])

import unittest


class TestQuickSortFunction(unittest.TestCase):

    def test_one_elment(self):
        self.assertEqual(qsort([1]), [1])
    
    def test_two_elments(self):
        self.assertEqual(qsort([3, 2]), [2, 3])
    
    def test_arrays(self):
        self.assertEqual(qsort([1, 2, 18, 21, 4]), sorted([1, 2, 18, 21, 4]))


if __name__ == '__main__':
    unittest.main()
