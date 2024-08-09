class Solution:
  def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
    ans = -1
    l = 1
    r = int(1e7)

    def time(speed: int) -> float:
      summ = 0
      for i in range(len(dist) - 1):
        summ += math.ceil(dist[i] / speed)
      return summ + dist[-1] / speed

    while l <= r:
      m = (l + r) // 2
      if time(m) > hour:
        l = m + 1
      else:
        ans = m
        r = m - 1

    return ans
