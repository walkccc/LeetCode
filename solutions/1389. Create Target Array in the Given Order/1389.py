class Solution:
  def createTargetArray(self, nums, index):
    ans = []
    for num, i in zip(nums, index):
      ans.insert(i, num)
    return ans
