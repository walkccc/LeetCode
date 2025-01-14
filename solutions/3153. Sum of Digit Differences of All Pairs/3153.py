class Solution:
  def sumDigitDifferences(self, nums: list[int]) -> int:
    n = len(nums)
    digitSize = len(str(nums[0]))
    ans = 0

    denominator = 1
    for _ in range(digitSize):
      count = [0] * 10
      for num in nums:
        count[num // denominator % 10] += 1
      ans += sum(freq * (n - freq) for freq in count)
      denominator *= 10

    return ans // 2
