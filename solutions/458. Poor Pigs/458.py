class Solution:
  def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
    base = minutesToTest // minutesToDie + 1
    ans = 0
    x = 1
    while x < buckets:
      ans += 1
      x *= base
    return ans
