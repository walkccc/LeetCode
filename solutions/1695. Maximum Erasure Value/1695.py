class Solution:
  def maximumUniqueSubarray(self, nums: List[int]) -> int:
    ans = 0
    score = 0
    seen = set()

    l = 0
    for r, num in enumerate(nums):
      while num in seen:
        score -= nums[l]
        seen.remove(nums[l])
        l += 1
      seen.add(nums[r])
      score += nums[r]
      ans = max(ans, score)

    return ans
