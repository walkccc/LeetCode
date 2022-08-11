class Solution:
  def minmaxGasDist(self, stations: List[int], k: int) -> float:
    kErr = 1e-6
    l = 0
    r = stations[-1] - stations[0]

    # True if can use k or less gas stations to ensure
    # each adjacent distance between gas stations is at most m
    def possible(k: int, m: float) -> bool:
      for a, b in zip(stations, stations[1:]):
        diff = b - a
        if diff > m:
          k -= ceil(diff / m) - 1
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
