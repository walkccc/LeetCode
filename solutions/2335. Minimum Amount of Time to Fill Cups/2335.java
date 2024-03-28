class Solution {
  public int fillCups(int[] amount) {
    final int max = Arrays.stream(amount).max().getAsInt();
    final int sum = Arrays.stream(amount).sum();
    return Math.max(max, (sum + 1) / 2);
  }
}
