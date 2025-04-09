class Solution:
  def numberOfChild(self, n: int, k: int) -> int:
    # the time for the ball to return to 0
    roundTime = 2 * (n - 1)
    pos = k % roundTime
    return pos if pos < n else roundTime - pos
