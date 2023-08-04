class Solution:
  def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
    return math.ceil(log(buckets) / log(minutesToTest // minutesToDie + 1))
