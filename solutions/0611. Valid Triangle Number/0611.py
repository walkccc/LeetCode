class Solution:
  def triangleNumber(self, nums: List[int]) -> int:
    ans = 0

    nums.sort()

    for k in range(len(nums) - 1, 1, -1):
      i = 0
      j = k - 1
      while i < j:
        if nums[i] + nums[j] > nums[k]:
          ans += j - i
          j -= 1
        else:
          i += 1

    return ans
