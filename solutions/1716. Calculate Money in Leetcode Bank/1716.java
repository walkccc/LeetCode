class Solution {
  public int totalMoney(int n) {
    final int weeks = n / 7;
    final int firstWeek = trapezoid(1, 7);
    final int lastFullWeek = trapezoid(1 + weeks - 1, 7 + weeks - 1);
    final int remainingDays = trapezoid(1 + weeks, n % 7 + weeks);
    return (firstWeek + lastFullWeek) * weeks / 2 + remainingDays;
  }

  // Returns sum(a..b).
  private int trapezoid(int a, int b) {
    return (a + b) * (b - a + 1) / 2;
  }
}
