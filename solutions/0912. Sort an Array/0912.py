class Solution:
  def sortArray(self, nums: List[int]) -> List[int]:
    def mergeSort(A: List[int], l: int, r: int) -> None:
      if l >= r:
        return

      def merge(A: List[int], l: int, m: int, r: int) -> None:
        sorted = [0] * (r - l + 1)
        k = 0  # sorted's index
        i = l  # left's index
        j = m + 1  # right's index

        while i <= m and j <= r:
          if A[i] < A[j]:
            sorted[k] = A[i]
            k += 1
            i += 1
          else:
            sorted[k] = A[j]
            k += 1
            j += 1

        # put possible remaining left part to the sorted array
        while i <= m:
          sorted[k] = A[i]
          k += 1
          i += 1

        # put possible remaining right part to the sorted array
        while j <= r:
          sorted[k] = A[j]
          k += 1
          j += 1

        A[l:l + len(sorted)] = sorted

      m = (l + r) // 2
      mergeSort(A, l, m)
      mergeSort(A, m + 1, r)
      merge(A, l, m, r)

    mergeSort(nums, 0, len(nums) - 1)
    return nums
