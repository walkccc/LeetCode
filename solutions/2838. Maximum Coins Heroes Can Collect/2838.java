class Solution {
  public long[] maximumCoins(int[] heroes, int[] monsters, int[] coins) {
    Pair<Integer, Integer>[] monsterAndCoins = getSortedMonsterAndCoins(monsters, coins);
    long[] ans = new long[heroes.length];
    long[] coinsPrefix = new long[coins.length + 1];

    for (int i = 0; i < monsterAndCoins.length; ++i)
      coinsPrefix[i + 1] = coinsPrefix[i] + monsterAndCoins[i].getValue();

    for (int i = 0; i < heroes.length; ++i)
      ans[i] = coinsPrefix[firstGreaterEqual(monsterAndCoins, heroes[i])];

    return ans;
  }

  private Pair<Integer, Integer>[] getSortedMonsterAndCoins(int[] monsters, int[] coins) {
    Pair<Integer, Integer>[] monsterAndCoins = new Pair[monsters.length];
    for (int i = 0; i < monsters.length; ++i)
      monsterAndCoins[i] = new Pair<>(monsters[i], coins[i]);
    Arrays.sort(monsterAndCoins, (a, b) -> a.getKey() - b.getKey());
    return monsterAndCoins;
  }

  private int firstGreaterEqual(Pair<Integer, Integer>[] monsterAndCoins, int hero) {
    int l = 0;
    int r = monsterAndCoins.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if (monsterAndCoins[m].getKey() > hero)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
