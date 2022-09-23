class Solution {
  public int flipgame(int[] fronts, int[] backs) {
    int ans = 2001;
    Set<Integer> same = new HashSet<>();

    for (int i = 0; i < fronts.length; ++i)
      if (fronts[i] == backs[i])
        same.add(fronts[i]);

    for (final int f : fronts)
      if (!same.contains(f))
        ans = Math.min(ans, f);

    for (final int b : backs)
      if (!same.contains(b))
        ans = Math.min(ans, b);

    return ans == 2001 ? 0 : ans;
  }
}
