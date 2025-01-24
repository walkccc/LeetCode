class Solution {
  public long numberOfWeeks(int[] milestones) {
    // The best strategy is to pick "max, nonMax, max, nonMax, ...".
    final int mx = Arrays.stream(milestones).max().getAsInt();
    final long sum = Arrays.stream(milestones).asLongStream().sum();
    final long nonMax = sum - mx;
    return Math.min(sum, 2 * nonMax + 1);
  }
}
