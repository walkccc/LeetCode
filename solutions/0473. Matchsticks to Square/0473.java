class Solution {
  public boolean makesquare(int[] matchsticks) {
    if (matchsticks.length < 4)
      return false;

    final int perimeter = Arrays.stream(matchsticks).sum();
    if (perimeter % 4 != 0)
      return false;

    int[] edges = new int[4];
    Arrays.fill(edges, perimeter / 4);
    Arrays.sort(edges); // can't do "Arrays.sort(edges, (a, b) -> b - a);" in Java
    return dfs(matchsticks, matchsticks.length - 1, edges);
  }

  private boolean dfs(int[] matchsticks, int selected, int[] edges) {
    if (selected == -1)
      return Arrays.stream(edges).allMatch(edge -> edge == 0);

    for (int i = 0; i < 4; ++i) {
      if (matchsticks[selected] > edges[i])
        continue;
      edges[i] -= matchsticks[selected];
      if (dfs(matchsticks, selected - 1, edges))
        return true;
      edges[i] += matchsticks[selected];
    }

    return false;
  }
}
