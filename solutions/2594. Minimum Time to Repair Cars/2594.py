class Solution:
  def repairCars(self, ranks: list[int], cars: int) -> int:
    def numCarsFixed(minutes: int) -> int:
      #    r * n^2 = minutes
      # -> n = sqrt(minutes / r)
      return sum(math.isqrt(minutes // rank) for rank in ranks)

    return bisect.bisect_left(
        range(min(ranks) * cars**2), cars,
        key=lambda m: numCarsFixed(m))
