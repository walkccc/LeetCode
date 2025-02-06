class Solution:
  def distinctDifferenceArray(self, nums: list[int]) -> list[int]:
    kMax = 50
    ans = []
    prefixCount = [0] * (kMax + 1)
    suffixCount = [0] * (kMax + 1)
    distinctPrefix = 0
    distinctSuffix = 0

    for num in nums:
      if suffixCount[num] == 0:
        distinctSuffix += 1
      suffixCount[num] += 1

    for num in nums:
      if prefixCount[num] == 0:
        distinctPrefix += 1
      prefixCount[num] += 1
      if suffixCount[num] == 1:
        distinctSuffix -= 1
      suffixCount[num] -= 1
      ans.append(distinctPrefix - distinctSuffix)

    return ans
