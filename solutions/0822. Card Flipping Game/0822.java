class Solution {
  public int flipgame(int[] fronts, int[] backs) {
    final int kMax = 2001;
    int ans = kMax;
    Set<Integer> same = new HashSet<>();

    for (int i = 0; i < fronts.length; ++i)
      if (fronts[i] == backs[i])
        same.add(fronts[i]);

    for (final int front : fronts)
      if (!same.contains(front))
        ans = Math.min(ans, front);

    for (final int back : backs)
      if (!same.contains(back))
        ans = Math.min(ans, back);

    return ans == kMax ? 0 : ans;
  }
}
