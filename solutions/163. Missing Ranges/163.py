class Solution:
  def findMissingRanges(
      self,
      nums: list[int],
      lower: int,
      upper: int,
  ) -> list[list[int]]:
    def getRange(lo: int, hi: int) -> list[int]:
      if lo == hi:
        return [lo, lo]
      return [lo, hi]

    if not nums:
      return [getRange(lower, upper)]

    ans = []

    if nums[0] > lower:
      ans.append(getRange(lower, nums[0] - 1))

    for prev, curr in zip(nums, nums[1:]):
      if curr > prev + 1:
        ans.append(getRange(prev + 1, curr - 1))

    if nums[-1] < upper:
      ans.append(getRange(nums[-1] + 1, upper))

    return ans
