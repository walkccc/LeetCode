class Solution:
  def threeSumSmaller(self, nums: List[int], target: int) -> int:
    if len(nums) < 3:
      return 0

    ans = 0

    nums.sort()

    for i in range(len(nums) - 2):
      l = i + 1
      r = len(nums) - 1
      while l < r:
        if nums[i] + nums[l] + nums[r] < target:
          # (nums[i], nums[l], nums[r])
          # (nums[i], nums[l], nums[r - 1])
          # ...,
          # (nums[i], nums[l], nums[l + 1])
          ans += r - l
          l += 1
        else:
          r -= 1

    return ans
