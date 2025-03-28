class Solution:
  def sortArray(self, nums: list[int]) -> list[int]:
    self._mergeSort(nums, 0, len(nums) - 1)
    return nums

  def _mergeSort(self, nums: list[int], l: int, r: int) -> None:
    if l >= r:
      return

    def merge(nums: list[int], l: int, m: int, r: int) -> None:
      sorted = [0] * (r - l + 1)
      k = 0  # sorted's index
      i = l  # left's index
      j = m + 1  # right's index

      while i <= m and j <= r:
        if nums[i] < nums[j]:
          sorted[k] = nums[i]
          k += 1
          i += 1
        else:
          sorted[k] = nums[j]
          k += 1
          j += 1

      # Put the possible remaining left part into the sorted array.
      while i <= m:
        sorted[k] = nums[i]
        k += 1
        i += 1

      # Put the possible remaining right part into the sorted array.
      while j <= r:
        sorted[k] = nums[j]
        k += 1
        j += 1

      nums[l:l + len(sorted)] = sorted

    m = (l + r) // 2
    self._mergeSort(nums, l, m)
    self._mergeSort(nums, m + 1, r)
    merge(nums, l, m, r)
