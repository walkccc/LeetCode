class Solution:
  def minMaxGame(self, nums: List[int]) -> int:
    if len(nums) == 1:
      return nums[0]

    nextNums = []
    for i in range(len(nums) // 2):
      nextNums.append(max(nums[2 * i], nums[2 * i + 1]) if i & 1 else
                      min(nums[2 * i], nums[2 * i + 1]))
    return self.minMaxGame(nextNums)
