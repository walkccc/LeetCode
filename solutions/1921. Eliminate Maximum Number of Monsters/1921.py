class Solution:
  def eliminateMaximum(self, dist: list[int], speed: list[int]) -> int:
    for i, arrivalTime in enumerate(
            sorted([(d - 1) // s for d, s in zip(dist, speed)])):
      if i > arrivalTime:
        return i
    return len(dist)
