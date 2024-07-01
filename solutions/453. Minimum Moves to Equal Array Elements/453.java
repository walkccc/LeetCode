class Solution {
  public int minMoves(int[] nums) {
    final int sum = Arrays.stream(nums).sum();
    final int min = Arrays.stream(nums).min().getAsInt();
    return sum - min * nums.length;
  }
}
