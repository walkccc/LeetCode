class Solution {
  public boolean xorGame(int[] nums) {
    final int xors = Arrays.stream(nums).reduce((a, b) -> a ^ b).getAsInt();
    return xors == 0 || nums.length % 2 == 0;
  }
}
