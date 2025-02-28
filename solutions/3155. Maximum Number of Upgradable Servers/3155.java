class Solution {
  public int[] maxUpgrades(int[] count, int[] upgrade, int[] sell, int[] money) {
    // If there's enough money, upgrade all servers; otherwise, optimize by
    // upgrading x servers. We have x * upgrade <= money + (count - x) * sell.
    // Therefore, x = (money + count * sell) / (sell + upgrade).
    int[] ans = new int[count.length];
    for (int i = 0; i < count.length; ++i)
      ans[i] = Math.min(count[i], //
                        (int) ((money[i] + 1L * count[i] * sell[i]) / (sell[i] + upgrade[i])));
    return ans;
  }
}
