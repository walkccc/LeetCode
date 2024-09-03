class Solution:
  def targetIndices(self, nums: list[int], target: int) -> list[int]:
    count = nums.count(target)
    lessThan = sum(num < target for num in nums)
    return [i for i in range(lessThan, lessThan + count)]
