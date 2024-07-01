class Solution:
  def minOperations(self, nums: List[int]) -> int:
    ans = 0
    last = 0

    for num in nums:
      ans += max(0, last - num + 1)
      last = max(num, last + 1)

    return ans
