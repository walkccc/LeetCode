class Solution {
  public int minMoves2(int[] nums) {
    final int n = nums.length;
    final int median = quickSelect(nums, 0, n - 1, (n + 1) / 2);
    int ans = 0;

    for (final int num : nums)
      ans += Math.abs(num - median);

    return ans;
  }

  private int quickSelect(int[] nums, int l, int r, int k) {
    final int randIndex = new Random().nextInt(r - l + 1) + l;
    swap(nums, randIndex, r);
    final int pivot = nums[r];

    int nextSwapped = l;
    for (int i = l; i < r; ++i)
      if (nums[i] <= pivot)
        swap(nums, nextSwapped++, i);
    swap(nums, nextSwapped, r);

    final int count = nextSwapped - l + 1;
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
