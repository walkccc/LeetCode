class Solution {
  public int minimumOperations(int[] nums) {
    return (int) Arrays.stream(nums).filter(num -> num % 3 != 0).count();
  }
}
