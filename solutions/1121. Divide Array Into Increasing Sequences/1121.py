class Solution:
  def canDivideIntoSubsequences(self, nums: List[int], k: int) -> bool:
    # Find the number with the maxFreq, we need at least maxFreq * k elements
    # e.g. nums = [1, 2, 2, 3, 4], we have maxFreq = 2 (two 2s), so we have to
    # Split nums into two subsequences say k = 3, the minimum length of nums is 2 x
    # 3 = 6, which is impossible if len(nums) = 5
    return len(nums) >= k * max(Counter(nums).values())
