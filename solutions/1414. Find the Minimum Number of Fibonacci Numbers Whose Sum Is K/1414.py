class Solution:
  def findMinFibonacciNumbers(self, k: int) -> int:
    if k < 2:  # k == 0 or k == 1
      return k

    a = 1  # F_1
    b = 1  # F_2

    while b <= k:
      #    a, b = F_{i + 1}, F_{i + 2}
      # -> a, b = F_{i + 2}, F_{i + 3}
      a, b = b, a + b

    return 1 + self.findMinFibonacciNumbers(k - a)
