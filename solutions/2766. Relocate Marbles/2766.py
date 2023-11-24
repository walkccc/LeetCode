class Solution:
  def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
    numsSet = set(nums)

    for f, t in zip(moveFrom, moveTo):
      numsSet.remove(f)
      numsSet.add(t)

    return sorted(numsSet)
