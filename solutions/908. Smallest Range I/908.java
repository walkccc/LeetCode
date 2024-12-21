class Solution {
  public int smallestRangeI(int[] nums, int k) {
    final int mx = Arrays.stream(nums).max().getAsInt();
    final int mn = Arrays.stream(nums).min().getAsInt();
    return Math.max(0, mx - mn - 2 * k);
  }
}
