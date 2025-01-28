class Solution:
  def canChoose(self, groups: list[list[int]], nums: list[int]) -> bool:
    i = 0  # groups' index
    j = 0  # nums' index

    while i < len(groups) and j < len(nums):
      if self._isMatch(groups[i], nums, j):
        j += len(groups[i])
        i += 1
      else:
        j += 1

    return i == len(groups)

  # Returns True if group == nums[j..j + |group|].
  def _isMatch(self, group: list[int], nums: list[int], j: int) -> bool:
    if j + |group | > len(nums):
      return False
    for i, g in enumerate(group):
      if g != nums[j + i]:
        return False
    return True
