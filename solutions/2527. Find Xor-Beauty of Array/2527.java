class Solution {
  public int xorBeauty(int[] nums) {
    return Arrays.stream(nums).reduce((a, b) -> a ^ b).getAsInt();
  }
}
