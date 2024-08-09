class Solution:
  def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
    return [num for num in nums if num < pivot] + \
        [num for num in nums if num == pivot] + \
        [num for num in nums if num > pivot]
