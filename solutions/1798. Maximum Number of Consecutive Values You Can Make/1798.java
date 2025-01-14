class Solution {
  public int getMaximumConsecutive(int[] coins) {
    int ans = 1; // the next value we want to make

    Arrays.sort(coins);

    for (final int coin : coins) {
      if (coin > ans)
        return ans;
      ans += coin;
    }

    return ans;
  }
}
