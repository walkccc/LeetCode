class Solution:
  def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
    max = (1 << maximumBit) - 1
    ans = []
    xors = 0

    for num in nums:
      xors ^= num
      ans.append(xors ^ max)

    return ans[::-1]
