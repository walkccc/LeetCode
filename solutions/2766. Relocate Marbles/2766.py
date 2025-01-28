class Solution:
  def relocateMarbles(
      self,
      nums: list[int],
      moveFrom: list[int],
      moveTo: list[int],
  ) -> list[int]:
    numsSet = set(nums)

    for f, t in zip(moveFrom, moveTo):
      numsSet.remove(f)
      numsSet.add(t)

    return sorted(numsSet)
