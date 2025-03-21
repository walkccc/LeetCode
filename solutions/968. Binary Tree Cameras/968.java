class Solution {
  public int minCameraCover(TreeNode root) {
    int[] ans = dfs(root);
    return Math.min(ans[1], ans[2]);
  }

  // 0 := all the nodes below the root are covered except the root
  // 1 := all the nodes below and including the root are covered with no camera
  // 2 := all nodes below and including the root are covered with a camera
  private int[] dfs(TreeNode root) {
    if (root == null)
      return new int[] {0, 0, 1000};

    int[] l = dfs(root.left);
    int[] r = dfs(root.right);

    final int s0 = l[1] + r[1];
    final int s1 = Math.min(l[2] + Math.min(r[1], r[2]), //
                            r[2] + Math.min(l[1], l[2]));
    final int s2 = Math.min(l[0], Math.min(l[1], l[2])) + //
                   Math.min(r[0], Math.min(r[1], r[2])) + 1;

    return new int[] {s0, s1, s2};
  }
}
