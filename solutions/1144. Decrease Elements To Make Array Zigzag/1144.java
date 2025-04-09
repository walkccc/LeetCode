class Solution {
  public int movesToMakeZigzag(int[] nums) {
    int[] decreasing = new int[2];

    for (int i = 0; i < nums.length; ++i) {
      int l = i > 0 ? nums[i - 1] : 1001;
      int r = i + 1 < nums.length ? nums[i + 1] : 1001;
      decreasing[i % 2] += Math.max(0, nums[i] - Math.min(l, r) + 1);
    }

    return Math.min(decreasing[0], decreasing[1]);
  }
}
