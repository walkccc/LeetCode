class Solution:
  def shipWithinDays(self, weights: List[int], D: int) -> int:
    l = max(weights)
    r = sum(weights)

    while l < r:
      m = (l + r) // 2
      day = 1
      capacity = 0
      for weight in weights:
        if capacity + weight > m:
          day += 1
          capacity = weight
        else:
          capacity += weight
      if day <= D:
        r = m
      else:
        l = m + 1

    return l
