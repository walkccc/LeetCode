class Solution:
  def shipWithinDays(self, weights: List[int], days: int) -> int:
    l = max(weights)
    r = sum(weights)

    def shipDays(shipCapacity: int) -> int:
      days = 1
      capacity = 0
      for weight in weights:
        if capacity + weight > shipCapacity:
          days += 1
          capacity = weight
        else:
          capacity += weight
      return days

    while l < r:
      m = (l + r) // 2
      if shipDays(m) <= days:
        r = m
      else:
        l = m + 1

    return l
