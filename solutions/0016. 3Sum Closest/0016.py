class Solution:
  def threeSumClosest(self, nums: List[int], target: int) -> int:
    ans = nums[0] + nums[1] + nums[2]

    nums.sort()

    for i in range(len(nums) - 2):
      if i > 0 and nums[i] == nums[i - 1]:
        continue
      l = i + 1
      r = len(nums) - 1
      while l < r:
        summ = nums[i] + nums[l] + nums[r]
        if summ == target:
          return summ
        if abs(summ - target) < abs(ans - target):
          ans = summ
        if summ < target:
          l += 1
        else:
          r -= 1

    return ans
