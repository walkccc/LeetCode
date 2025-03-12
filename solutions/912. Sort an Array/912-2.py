class Solution:
  def sortArray(self, nums: list[int]) -> list[int]:
    self._heapSort(nums)
    return nums

  def _heapSort(self, nums: list[int]) -> None:
    def maxHeapify(nums: list[int], i: int, heapSize: int) -> None:
      l = 2 * i + 1
      r = 2 * i + 2
      largest = i
      if l < heapSize and nums[largest] < nums[l]:
        largest = l
      if r < heapSize and nums[largest] < nums[r]:
        largest = r
      if largest != i:
        nums[largest], nums[i] = nums[i], nums[largest]
        maxHeapify(nums, largest, heapSize)

    def buildMaxHeap(nums: list[int]) -> None:
      for i in range(len(nums) // 2, -1, -1):
        maxHeapify(nums, i, len(nums))

    buildMaxHeap(nums)
    heapSize = len(nums)
    for i in reversed(range(1, len(nums))):
      nums[i], nums[0] = nums[0], nums[i]
      heapSize -= 1
      maxHeapify(nums, 0, heapSize)
