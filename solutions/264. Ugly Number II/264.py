class Solution:
  def nthUglyNumber(self, n: int) -> int:
    nums = [1]
    i2 = 0
    i3 = 0
    i5 = 0

    while len(nums) < n:
      next2 = nums[i2] * 2
      next3 = nums[i3] * 3
      next5 = nums[i5] * 5
      next = min(next2, next3, next5)
      if next == next2:
        i2 += 1
      if next == next3:
        i3 += 1
      if next == next5:
        i5 += 1
      nums.append(next)

    return nums[-1]
