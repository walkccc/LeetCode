class Solution:
  def minDeletion(self, nums: List[int]) -> int:
    ans = 0

    for i in range(len(nums) - 1):
      # i - ans := index after deletion
      if nums[i] == nums[i + 1] and (i - ans) % 2 == 0:
        ans += 1

    # add one if the length after deletion is odd
    return ans + ((len(nums) - ans) & 1)
