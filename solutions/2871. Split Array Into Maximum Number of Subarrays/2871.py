class Solution:
  def maxSubarrays(self, nums: List[int]) -> int:
    ans = 0
    score = 0

    for num in nums:
      score = num if score == 0 else score & num
      if score == 0:
        ans += 1

    return max(1, ans)
