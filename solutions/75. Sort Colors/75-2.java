class Solution {
  public void sortColors(int[] nums) {
    int l = 0;               // The next 0 should be placed in l.
    int r = nums.length - 1; // THe next 2 should be placed in r.

    for (int i = 0; i <= r;)
      if (nums[i] == 0)
        swap(nums, i++, l++);
      else if (nums[i] == 1)
        ++i;
      else
        // We may swap a 0 to index i, but we're still not sure whether this 0
        // is placed in the correct index, so we can't move pointer i.
        swap(nums, i, r--);
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
