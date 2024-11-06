class Solution:
  def findMaxK(self, nums: list[int]) -> int:
    ans = -1
    seen = set()

    for num in nums:
      if -num in seen:
        ans = max(ans, abs(num))
      else:
        seen.add(num)

    return ans
