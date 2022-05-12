class Solution:
  def findKthLargest(self, nums: List[int], k: int) -> int:
    def quickSelect(l: int, r: int, k: int) -> int:
      pivot = nums[r]

      nextSwapped = l
      for i in range(l, r):
        if nums[i] >= pivot:
          nums[nextSwapped], nums[i] = nums[i], nums[nextSwapped]
          nextSwapped += 1
      nums[nextSwapped], nums[r] = nums[r], nums[nextSwapped]

      count = nextSwapped - l + 1  # number of nums >= pivot
      if count == k:
        return nums[nextSwapped]
      if count > k:
        return quickSelect(l, nextSwapped - 1, k)
      return quickSelect(nextSwapped + 1, r, k - count)

    return quickSelect(0, len(nums) - 1, k)
