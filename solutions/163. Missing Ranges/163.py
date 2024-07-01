class Solution:
  def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
    def getRange(lo: int, hi: int) -> str:
      if lo == hi:
        return str(lo)
      return str(lo) + '->' + str(hi)

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
