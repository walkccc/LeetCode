class Solution:
  def countSubarrays(self, nums: list[int], k: int) -> int:
    maxNum = max(nums)
    ans = 0
    count = 0

    l = 0
    for r, num in enumerate(nums):
      if num == maxNum:
        count += 1
      # Keep the window to include k - 1 times of the maxNummum number.
      while count == k:
        if nums[l] == maxNum:
          count -= 1
        l += 1
      # If l > 0, nums[l:r+1] has k - 1 times of the maxNummum number. For any
      # subarray nums[i:r+1], where i < l, it will have at least k times of the
      # maxNummum number, since nums[l - 1] equals the maxNummum number.
      ans += l

    return ans
