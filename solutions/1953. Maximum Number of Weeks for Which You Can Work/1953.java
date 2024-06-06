class Solution {
  public long numberOfWeeks(int[] milestones) {
    // The best strategy is to pick "max, nonMax, max, nonMax, ...".
    final int max = Arrays.stream(milestones).max().getAsInt();
    final long sum = Arrays.stream(milestones).asLongStream().sum();
    final long nonMax = sum - max;
    return Math.min(sum, 2 * nonMax + 1);
  }
}
