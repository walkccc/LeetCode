class Solution {
  public int minOperations(int[] nums) {
    final int mx = Arrays.stream(nums).max().getAsInt();
    return Arrays.stream(nums).map(num -> Integer.bitCount(num)).sum() +
        (mx == 0 ? 0 : (int) (Math.log(mx) / Math.log(2)));
  }
}
