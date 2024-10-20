class Solution {
  public int fillCups(int[] amount) {
    final int mx = Arrays.stream(amount).max().getAsInt();
    final int sum = Arrays.stream(amount).sum();
    return Math.max(mx, (sum + 1) / 2);
  }
}
