class Solution {
  public int[] sortArray(int[] nums) {
    heapSort(nums);
    return nums;
  }

  private void heapSort(int[] A) {
    buildMaxHeap(A);
    int heapSize = A.length;
    for (int i = A.length - 1; i > 0; --i) {
      swap(A, i, 0);
      --heapSize;
      maxHeapify(A, 0, heapSize);
    }
  }

  private void buildMaxHeap(int[] A) {
    for (int i = A.length / 2; i >= 0; --i)
      maxHeapify(A, i, A.length);
  }

  private void maxHeapify(int[] A, int i, int heapSize) {
    final int l = 2 * i + 1;
    final int r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && A[largest] < A[l])
      largest = l;
    if (r < heapSize && A[largest] < A[r])
      largest = r;
    if (largest != i) {
      swap(A, largest, i);
      maxHeapify(A, largest, heapSize);
    }
  }

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
