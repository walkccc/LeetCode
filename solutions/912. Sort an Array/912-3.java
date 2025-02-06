class Solution {
  public int[] sortArray(int[] nums) {
    quickSort(nums, 0, nums.length - 1);
    return nums;
  }

  private void quickSort(int[] nums, int l, int r) {
    if (l >= r)
      return;

    final int m = partition(nums, l, r);
    quickSort(nums, l, m - 1);
    quickSort(nums, m + 1, r);
  }

  private int partition(int[] nums, int l, int r) {
    final int randIndex = new Random().nextInt(r - l + 1) + l;
    swap(nums, randIndex, r);
    final int pivot = nums[r];
    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (nums[i] <= pivot)
        swap(nums, nextSwapped++, i);
    swap(nums, nextSwapped, r);
    return nextSwapped;
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
