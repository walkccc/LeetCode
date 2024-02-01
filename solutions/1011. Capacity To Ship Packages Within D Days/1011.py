class Solution:
  def shipWithinDays(self, weights: List[int], days: int) -> int:
    def canShip(shipCapacity: int) -> bool:
      shipDays = 1
      capacity = 0
      for weight in weights:
        if capacity + weight > shipCapacity:
          shipDays += 1
          capacity = weight
        else:
          capacity += weight
      return shipDays <= days

    l = max(weights)
    r = sum(weights)
    return bisect.bisect_left(range(l, r), True,
                              key=lambda m: canShip(m)) + l
