class Solution {
  public int maxProfit(int[] inventory, int orders) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    long largestCount = 1;

    Arrays.sort(inventory);

    for (int i = inventory.length - 1; i >= 0; --i, ++largestCount)
      if (i == 0 || inventory[i] > inventory[i - 1]) {
        // If we are at the first inventory, or inventory[i] > inventory[i + 1].
        // In either case, we will pick inventory[i..i + largestCount - 1].
        final long pick = (i == 0) ? inventory[i] : inventory[i] - inventory[i - 1];
        if (largestCount * pick >= orders) {
          // We have run out of orders, so we need to recalculate the number of
          // balls that we actually pick for inventory[i..i + largestCount - 1].
          final long actualPick = orders / largestCount;
          final long remaining = orders % largestCount;
          return (int) ((ans +
                         largestCount * trapezoid(inventory[i], inventory[i] - actualPick + 1) +
                         remaining * (inventory[i] - actualPick)) %
                        kMod);
        }
        ans += largestCount * trapezoid(inventory[i], inventory[i] - pick + 1);
        ans %= kMod;
        orders -= largestCount * pick;
      }

    throw new IllegalArgumentException();
  }

  private long trapezoid(long a, long b) {
    return (a + b) * (a - b + 1) / 2;
  }
}
