class Solution:
  def resultArray(self, nums: list[int]) -> list[int]:
    arr1 = [nums[0]]
    arr2 = [nums[1]]

    for i in range(2, len(nums)):
      if arr1[-1] > arr2[-1]:
        arr1.append(nums[i])
      else:
        arr2.append(nums[i])

    return arr1 + arr2
