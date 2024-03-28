class Solution {
  public int[] sortArray(int[] nums) {
    quickSort(nums, 0, nums.length - 1);
    return nums;
  }

  private void quickSort(int[] A, int l, int r) {
    if (l >= r)
      return;

    final int m = partition(A, l, r);
    quickSort(A, l, m - 1);
    quickSort(A, m + 1, r);
  }

  private int partition(int[] A, int l, int r) {
    final int randIndex = new Random().nextInt(r - l + 1) + l;
    swap(A, randIndex, r);
    final int pivot = A[r];
    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (A[i] <= pivot)
        swap(A, nextSwapped++, i);
    swap(A, nextSwapped, r);
    return nextSwapped;
  }

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
