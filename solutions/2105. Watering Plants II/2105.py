class Solution:
  def minimumRefill(
      self,
      plants: list[int],
      capacityA: int,
      capacityB: int,
  ) -> int:
    ans = 0
    i = 0
    j = len(plants) - 1
    canA = capacityA
    canB = capacityB

    while i < j:
      ans += (canA < plants[i]) + (canB < plants[j])
      if canA < plants[i]:
        canA = capacityA
      if canB < plants[j]:
        canB = capacityB
      canA -= plants[i]
      canB -= plants[j]
      i += 1
      j -= 1

    return ans + (i == j and max(canA, canB) < plants[i])
