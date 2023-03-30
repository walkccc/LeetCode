class Solution:
  def repairCars(self, ranks: List[int], cars: int) -> int:
    def numCarsFixed(minutes: int) -> int:
      #    r * n^2 = minutes
      # -> n = sqrt(minutes / r)
      return sum(int(sqrt(minutes // rank)) for rank in ranks)

    return bisect.bisect_left(
        range(0, min(ranks) * cars**2), cars,
        key=lambda m: numCarsFixed(m))
