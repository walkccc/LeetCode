class Solution:
  def sortArray(self, nums: list[int]) -> list[int]:
    def heapSort(A: list[int]) -> None:
      def maxHeapify(A: list[int], i: int, heapSize: int) -> None:
        l = 2 * i + 1
        r = 2 * i + 2
        largest = i
        if l < heapSize and A[largest] < A[l]:
          largest = l
        if r < heapSize and A[largest] < A[r]:
          largest = r
        if largest != i:
          A[largest], A[i] = A[i], A[largest]
          maxHeapify(A, largest, heapSize)

      def buildMaxHeap(A: list[int]) -> None:
        for i in range(len(A) // 2, -1, -1):
          maxHeapify(A, i, len(A))

      buildMaxHeap(A)
      heapSize = len(A)
      for i in reversed(range(1, len(A))):
        A[i], A[0] = A[0], A[i]
        heapSize -= 1
        maxHeapify(A, 0, heapSize)

    heapSort(nums)
    return nums
