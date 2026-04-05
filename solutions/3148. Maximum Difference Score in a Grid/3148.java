class Solution {
  public int maxScore(List<List<Integer>> grid) {
    final int MAX = 200_000;
    int ans = -MAX;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid.get(0).size(); ++j) {
        final int prevMin = Math.min(i > 0 ? grid.get(i - 1).get(j) : MAX, //
                                     j > 0 ? grid.get(i).get(j - 1) : MAX);
        ans = Math.max(ans, grid.get(i).get(j) - prevMin);
        if (prevMin < grid.get(i).get(j))
          grid.get(i).set(j, prevMin);
      }

    return ans;
  }
}
