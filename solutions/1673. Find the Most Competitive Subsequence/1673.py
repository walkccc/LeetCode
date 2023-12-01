class Solution:
  def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
    ans = []

    for i, num in enumerate(nums):
      # If |ans| - 1 + |nums[i..n)| >= k, then it means we still have enough
      # numbers, and we can safely pop an element from ans.
      while ans and ans[-1] > nums[i] and len(ans) - 1 + len(nums) - i >= k:
        ans.pop()
      if len(ans) < k:
        ans.append(nums[i])

    return ans
