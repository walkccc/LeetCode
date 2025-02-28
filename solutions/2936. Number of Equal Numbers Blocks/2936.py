# Definition for BigArray.
# class BigArray:
#   def at(self, index: long) -> int:
#     pass
#   def size(self) -> long:
#     pass

class Solution(object):
  def countBlocks(self, nums: Optional['BigArray']) -> int:
    def countBlocks(l: int, r: int, leftValue: int, rightValue: int) -> int:
      """Returns the number of maximal blocks in nums[l..r]."""
      if leftValue == rightValue:
        return 1
      if l + 1 == r:
        return 2
      m = (l + r) // 2
      midValue = nums.at(m)
      return (countBlocks(l, m, leftValue, midValue) +
              countBlocks(m, r, midValue, rightValue) - 1)
    # Substract nums[m], which will be counted twice.
    return countBlocks(0, nums.size() - 1,
                       nums.at(0), nums.at(nums.size() - 1))
