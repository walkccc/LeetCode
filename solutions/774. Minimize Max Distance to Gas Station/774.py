class Solution:
  def minmaxGasDist(self, stations: list[int], k: int) -> float:
    kErr = 1e-6
    l = 0
    r = stations[-1] - stations[0]

    def possible(k: int, m: float) -> bool:
      """
      Returns True if can use <= k gas stations to ensure that each adjacent
      distance between gas stations <= m.
      """
      for a, b in zip(stations, stations[1:]):
        diff = b - a
        if diff > m:
          k -= math.ceil(diff / m) - 1
          if k < 0:
            return False
      return True

    while r - l > kErr:
      m = (l + r) / 2
      if possible(k, m):
        r = m
      else:
        l = m

    return l
