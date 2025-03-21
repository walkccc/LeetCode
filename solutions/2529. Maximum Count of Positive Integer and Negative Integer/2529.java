class Solution {
  public int maximumCount(int[] nums) {
    return (int) Math.max(Arrays.stream(nums).filter(num -> num > 0).count(),
                          Arrays.stream(nums).filter(num -> num < 0).count());
  }
}
