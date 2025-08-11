class Solution:
  def divideArray(self, nums: list[int], k: int) -> list[list[int]]:
    ans = []

    nums.sort()

    for i in range(2, len(nums), 3):
      if nums[i] - nums[i - 2] > k:
        return []
      ans.append([nums[i - 2], nums[i - 1], nums[i]])

    return ans
