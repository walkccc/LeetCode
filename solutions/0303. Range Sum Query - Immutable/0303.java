class NumArray {
  public NumArray(int[] nums) {
    prefix = new int[nums.length + 1];
    for (int i = 0; i < nums.length; ++i)
      prefix[i + 1] = nums[i] + prefix[i];
  }

  public int sumRange(int left, int right) {
    return prefix[right + 1] - prefix[left];
  }

  private int[] prefix;
}
