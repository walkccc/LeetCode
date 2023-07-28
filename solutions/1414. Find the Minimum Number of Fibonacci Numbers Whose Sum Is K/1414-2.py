class Solution:
  def findMinFibonacciNumbers(self, k: int) -> int:
    ans = 0
    a = 1  # F_1
    b = 1  # F_2

    while b <= k:
      #    a, b = F_{i + 1}, F_{i + 2}
      # -> a, b = F_{i + 2}, F_{i + 3}
      a, b = b, a + b

    while a > 0:
      if a <= k:
        k -= a
        ans += 1
      #    a, b = F_{i + 2}, F_{i + 3}
      # -> a, b = F_{i + 1}, F_{i + 2}
      a, b = b - a, a

    return ans
