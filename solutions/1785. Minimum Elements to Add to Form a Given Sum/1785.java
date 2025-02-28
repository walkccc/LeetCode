class Solution {
  public int minElements(int[] nums, int limit, int goal) {
    final long sum = Arrays.stream(nums).asLongStream().sum();
    final double diff = Math.abs(goal - sum);
    return (int) Math.ceil(diff / limit);
  }
}
