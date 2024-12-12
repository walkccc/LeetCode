class Solution:
  def maximumSum(self, nums: list[int]) -> int:
    kMax = 9 * 9  # 999,999,999
    ans = -1
    count = [[] for _ in range(kMax + 1)]

    for num in nums:
      count[self._getDigitSum(num)].append(num)

    for groupNums in count:
      if len(groupNums) < 2:
        continue
      groupNums.sort(reverse=True)
      ans = max(ans, groupNums[0] + groupNums[1])

    return ans

  def _getDigitSum(self, num: int) -> int:
    return sum(int(digit) for digit in str(num))
