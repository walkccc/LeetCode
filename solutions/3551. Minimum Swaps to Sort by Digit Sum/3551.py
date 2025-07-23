class Solution:
  def minSwaps(self, nums: list[int]) -> int:
    ans = 0
    seen = set()
    sortedNums = sorted(nums, key=lambda x: (self._getDigitSum(x), x))
    numToIndex = {num: i for i, num in enumerate(sortedNums)}

    for i, num in enumerate(nums):
      if i in seen or numToIndex[num] == i:
        continue
      cycleSize = 0
      j = i
      while j not in seen:
        seen.add(j)
        j = numToIndex[nums[j]]
        cycleSize += 1
      ans += max(cycleSize - 1, 0)
    return ans

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
