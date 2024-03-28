class Solution {
  public int pathSum(int[] nums) {
    int[][] tree = new int[4][8];
    Arrays.stream(tree).forEach(A -> Arrays.fill(A, -1));

    for (final int num : nums) {
      final int d = num / 100 - 1;
      final int p = (num % 100) / 10 - 1;
      final int v = num % 10;
      tree[d][p] = v;
    }

    dfs(tree, 0, 0, 0);
    return ans;
  }

  private int ans = 0;

  private void dfs(int[][] tree, int i, int j, int path) {
    if (tree[i][j] == -1)
      return;
    if (i == 3 || Math.max(tree[i + 1][j * 2], tree[i + 1][j * 2 + 1]) == -1) {
      ans += path + tree[i][j];
      return;
    }

    dfs(tree, i + 1, j * 2, path + tree[i][j]);
    dfs(tree, i + 1, j * 2 + 1, path + tree[i][j]);
  }
}
