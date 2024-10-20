class Solution {
  public int[] getSubarrayBeauty(int[] nums, int k, int x) {
    int[] ans = new int[nums.length - k + 1];
    int[] count = new int[50]; // count[i] := the frequency of (i + 50)

    for (int i = 0; i < nums.length; ++i) {
      if (nums[i] < 0)
        ++count[nums[i] + 50];
      if (i - k >= 0 && nums[i - k] < 0)
        --count[nums[i - k] + 50];
      if (i + 1 >= k)
        ans[i - k + 1] = getXthSmallestNum(count, x);
    }

    return ans;
  }

  private int getXthSmallestNum(int[] count, int x) {
    int prefix = 0;
    for (int i = 0; i < 50; ++i) {
      prefix += count[i];
      if (prefix >= x)
        return i - 50;
    }
    return 0;
  }
}
