class Solution {
  public int[] sortArray(int[] nums) {
    mergeSort(nums, 0, nums.length - 1);
    return nums;
  }

  private void mergeSort(int[] nums, int l, int r) {
    if (l >= r)
      return;
    final int m = (l + r) / 2;
    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);
  }

  private void merge(int[] nums, int l, int m, int r) {
    int[] sorted = new int[r - l + 1];
    int k = 0;     // sorted's index
    int i = l;     // left's index
    int j = m + 1; // right's index

    while (i <= m && j <= r)
      if (nums[i] < nums[j])
        sorted[k++] = nums[i++];
      else
        sorted[k++] = nums[j++];

    // Put the possible remaining left part into the sorted array.
    while (i <= m)
      sorted[k++] = nums[i++];

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = nums[j++];

    System.arraycopy(sorted, 0, nums, l, sorted.length);
  }
}
