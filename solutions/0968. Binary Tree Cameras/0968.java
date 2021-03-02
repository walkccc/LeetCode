class Solution {
  public int minCameraCover(TreeNode root) {
    int[] ans = dfs(root);
    return Math.min(ans[1], ans[2]);
  }

  // 0 := all nodes below root are covered except root
  // 1 := all nodes below and including root are covered w/o camera here
  // 2 := all nodes below and including root are covered w/ camera here
  private int[] dfs(TreeNode root) {
    if (root == null)
      return new int[] {0, 0, 1000};

    int[] l = dfs(root.left);
    int[] r = dfs(root.right);

    final int s0 = l[1] + r[1];
    final int s1 = Math.min(l[2] + Math.min(r[1], r[2]),
                            r[2] + Math.min(l[1], l[2]));
    final int s2 = 1 + Math.min(l[0], Math.min(l[1], l[2])) +
                       Math.min(r[0], Math.min(r[1], r[2]));

    return new int[] { s0, s1, s2 };
  }
}
