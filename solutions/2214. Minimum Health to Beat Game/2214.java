class Solution {
  public long minimumHealth(int[] damage, int armor) {
    final long sum = Arrays.stream(damage).asLongStream().sum();
    final int maxDamage = Arrays.stream(damage).max().getAsInt();
    return 1 + sum - Math.min(maxDamage, armor);
  }
}
