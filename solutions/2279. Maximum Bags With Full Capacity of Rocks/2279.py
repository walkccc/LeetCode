class Solution:
  def maximumBags(
      self,
      capacity: list[int],
      rocks: list[int],
      additionalRocks: int,
  ) -> int:
    for i, d in enumerate(sorted([c - r for c, r in zip(capacity, rocks)])):
      if d > additionalRocks:
        return i
      additionalRocks -= d
    return len(capacity)
