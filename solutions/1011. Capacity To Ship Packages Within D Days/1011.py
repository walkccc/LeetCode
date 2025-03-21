class Solution:
  def shipWithinDays(self, weights: list[int], days: int) -> int:
    def shipDays(shipCapacity: int) -> int:
      shipDays = 1
      capacity = 0
      for weight in weights:
        if capacity + weight > shipCapacity:
          shipDays += 1
          capacity = weight
        else:
          capacity += weight
      return shipDays

    l = max(weights)
    r = sum(weights)
    return bisect.bisect_left(range(l, r), True,
                              key=lambda m: shipDays(m) <= days) + l
