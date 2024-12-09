class Solution {
  public int maxScore(List<List<Integer>> grid) {
    final int kMax = 200_000;
    int ans = -kMax;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid.get(0).size(); ++j) {
        final int prevMin = Math.min(i > 0 ? grid.get(i - 1).get(j) : kMax, //
                                     j > 0 ? grid.get(i).get(j - 1) : kMax);
        ans = Math.max(ans, grid.get(i).get(j) - prevMin);
        if (prevMin < grid.get(i).get(j))
          grid.get(i).set(j, prevMin);
      }

    return ans;
  }
}
