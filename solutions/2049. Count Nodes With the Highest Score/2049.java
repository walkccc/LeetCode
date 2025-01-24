class Solution {
  public int countHighestScoreNodes(int[] parents) {
    List<Integer>[] tree = new List[parents.length];

    for (int i = 0; i < tree.length; ++i)
      tree[i] = new ArrayList<>();

    for (int i = 0; i < parents.length; ++i) {
      if (parents[i] == -1)
        continue;
      tree[parents[i]].add(i);
    }

    dfs(tree, 0);
    return ans;
  }

  private int ans = 0;
  private long maxScore = 0;

  private int dfs(List<Integer>[] tree, int u) {
    int count = 1;
    long score = 1;
    for (final int v : tree[u]) {
      final int childCount = dfs(tree, v);
      count += childCount;
      score *= childCount;
    }
    final int aboveCount = tree.length - count;
    score *= Math.max(aboveCount, 1);
    if (score > maxScore) {
      maxScore = score;
      ans = 1;
    } else if (score == maxScore) {
      ++ans;
    }
    return count;
  }
}
