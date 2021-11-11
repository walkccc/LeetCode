class Solution {
  public int maxSumBST(TreeNode root) {
    dfs(root);

    return ans;
  }

  private int ans = 0;

  private Info dfs(TreeNode root) {
    if (root == null)
      return new Info(Integer.MAX_VALUE, Integer.MIN_VALUE, 0, true);

    Info left = dfs(root.left);
    Info right = dfs(root.right);
    boolean valid = left.valid && right.valid && root.val > left.max && root.val < right.min;
    int sum = valid ? root.val + left.sum + right.sum : -1;
    ans = Math.max(ans, sum);

    return new Info(Math.min(root.val, left.min), Math.max(root.val, right.max), sum, valid);
  }

  private class Info {
    int min;
    int max;
    int sum;
    boolean valid;

    public Info(int min, int max, int sum, boolean valid) {
      this.min = min;
      this.max = max;
      this.sum = sum;
      this.valid = valid;
    }
  }
}
