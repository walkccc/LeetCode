class Solution {
  public boolean canAliceWin(int[] nums) {
    return Arrays.stream(nums).map(num -> num < 10 ? num : -num).sum() != 0;
  }
}
