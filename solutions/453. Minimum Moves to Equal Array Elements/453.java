class Solution {
  public int minMoves(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    final int mn = Arrays.stream(nums).min().getAsInt();
    return sum - mn * nums.length;
  }
}
