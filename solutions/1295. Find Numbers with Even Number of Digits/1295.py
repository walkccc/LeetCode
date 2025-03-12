class Solution:
  def findNumbers(self, nums: list[int]) -> int:
    ans = 0

    for num in nums:
      if 9 < num < 100 or 999 < num < 10000 or num == 100000:
        ans += 1

    return ans
