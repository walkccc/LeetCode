class Solution {
  public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
    count(root, x);
    return Math.max(Math.max(leftCount, rightCount), n - leftCount - rightCount - 1) > n / 2;
  }

  private int leftCount;  // # of nodes of n's left
  private int rightCount; // # of nodes of n's right

  private int count(TreeNode root, int x) {
    if (root == null)
      return 0;

    final int l = count(root.left, x);
    final int r = count(root.right, x);

    if (root.val == x) {
      leftCount = l;
      rightCount = r;
    }

    return 1 + l + r;
  }
}
