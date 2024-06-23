class Solution {
  public int minOperations(int[] nums, int k) {
    return (int) Arrays.stream(nums).filter(num -> num < k).count();
  }
}
