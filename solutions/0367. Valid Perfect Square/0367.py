class Solution:
  def isPerfectSquare(self, num: int) -> bool:
    l = 1
    r = num

    while l < r:
      m = (l + r) // 2
      if m >= num / m:
        r = m
      else:
        l = m + 1

    return l * l == num
