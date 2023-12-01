class Solution:
  def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
    diff = (sum(aliceSizes) - sum(bobSizes)) // 2
    bobSizesSet = set(bobSizes)

    for aliceSize in aliceSizes:
      target = aliceSize - diff
      if target in bobSizesSet:
        return [aliceSize, target]
