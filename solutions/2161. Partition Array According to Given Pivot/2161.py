class Solution:
  def pivotArray(self, nums: list[int], pivot: int) -> list[int]:
    return ([num for num in nums if num < pivot] +
            [num for num in nums if num == pivot] +
            [num for num in nums if num > pivot])
