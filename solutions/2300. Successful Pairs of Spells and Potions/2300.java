class Solution {
  public int[] successfulPairs(int[] spells, int[] potions, long success) {
    int[] ans = new int[spells.length];
    Arrays.sort(potions);

    for (int i = 0; i < spells.length; ++i)
      ans[i] = potions.length - firstIndexSuccess(spells[i], potions, success);

    return ans;
  }

  // first index i s.t. spell * potions[i] >= success
  private int firstIndexSuccess(int spell, int[] potions, long success) {
    int l = 0;
    int r = potions.length;
    while (l < r) {
      final int m = (l + r) / 2;
      if ((long) spell * potions[m] >= success)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}
