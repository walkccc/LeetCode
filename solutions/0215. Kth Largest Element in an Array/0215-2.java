class Solution {
  public int findKthLargest(int[] nums, int k) {
    return quickSelect(nums, 0, nums.length - 1, k);
  }

  private int quickSelect(int[] nums, int left, int right, int k) {
    int l = left; // next swapped index

    for (int i = left; i < right; ++i)
      if (nums[i] >= nums[right]) // nums[right] := the pivot
        swap(nums, l++, i);
    swap(nums, l, right);

    final int count = l - left + 1; // # of nums >= pivot
    if (count == k)
      return nums[l];
    if (count > k)
      return quickSelect(nums, left, l - 1, k);
    return quickSelect(nums, l + 1, right, k - count);
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}