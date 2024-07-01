class Solution {
  public int smallestRangeI(int[] nums, int k) {
    final int max = Arrays.stream(nums).max().getAsInt();
    final int min = Arrays.stream(nums).min().getAsInt();
    return Math.max(0, max - min - 2 * k);
  }
}
