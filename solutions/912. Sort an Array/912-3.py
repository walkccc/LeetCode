class Solution:
  def sortArray(self, nums: list[int]) -> list[int]:
    self._quickSort(nums, 0, len(nums) - 1)
    return nums

  def _quickSort(self, nums: list[int], l: int, r: int) -> None:
    if l >= r:
      return

    def partition(nums: list[int], l: int, r: int) -> int:
      randIndex = random.randint(0, r - l) + l
      nums[randIndex], nums[r] = nums[r], nums[randIndex]
      pivot = nums[r]
      nextSwapped = l
      for i in range(l, r):
        if nums[i] <= pivot:
          nums[nextSwapped], nums[i] = nums[i], nums[nextSwapped]
          nextSwapped += 1
      nums[nextSwapped], nums[r] = nums[r], nums[nextSwapped]
      return nextSwapped

    m = partition(nums, l, r)
    self._quickSort(nums, l, m - 1)
    self._quickSort(nums, m + 1, r)
