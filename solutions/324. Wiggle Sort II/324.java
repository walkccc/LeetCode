class Solution {
  public void wiggleSort(int[] nums) {
    final int n = nums.length;
    final int median = findKthLargest(nums, (n + 1) / 2);
    for (int i = 0, j = 0, k = n - 1; i <= k;)
      if (nums[A(i, n)] > median)
        swap(nums, A(i++, n), A(j++, n));
      else if (nums[A(i, n)] < median)
        swap(nums, A(i, n), A(k--, n));
      else
        ++i;
  }

  private int A(int i, int n) {
    return (1 + 2 * i) % (n | 1);
  }

  // Same as 215. Kth Largest Element in an Array
  private int findKthLargest(int[] nums, int k) {
    return quickSelect(nums, 0, nums.length - 1, k);
  }

  private int quickSelect(int[] nums, int l, int r, int k) {
    final int pivot = nums[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (nums[i] >= pivot)
        swap(nums, nextSwapped++, i);
    swap(nums, nextSwapped, r);

    final int count = nextSwapped - l + 1; // the number of `nums` >= pivot
    if (count == k)
      return nums[nextSwapped];
    if (count > k)
      return quickSelect(nums, l, nextSwapped - 1, k);
    return quickSelect(nums, nextSwapped + 1, r, k - count);
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
