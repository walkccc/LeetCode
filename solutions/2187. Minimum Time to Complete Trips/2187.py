class Solution:
  def minimumTime(self, time: List[int], totalTrips: int) -> int:
    l = 1
    r = min(time) * totalTrips

    while l < r:
      m = (l + r) // 2
      if sum(m // t for t in time) >= totalTrips:
        r = m
      else:
        l = m + 1

    return l
