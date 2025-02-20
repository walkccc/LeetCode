class Solution:
  def splitArray(self, nums: list[int], k: int) -> int:
    l = max(nums)
    r = sum(nums) + 1

    def numGroups(maxSumInGroup: int) -> int:
      groupCount = 1
      sumInGroup = 0

      for num in nums:
        if sumInGroup + num <= maxSumInGroup:
          sumInGroup += num
        else:
          groupCount += 1
          sumInGroup = num

      return groupCount

    while l < r:
      m = (l + r) // 2
      if numGroups(m) > k:
        l = m + 1
      else:
        r = m

    return l
