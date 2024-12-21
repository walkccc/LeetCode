class Solution {
  public int maxSumBST(TreeNode root) {
    traverse(root);
    return ans;
  }

  private record T(boolean isBST, Integer mx, Integer mn, Integer sum) {}

  private int ans = 0;

  private T traverse(TreeNode root) {
    if (root == null)
      return new T(true, Integer.MIN_VALUE, Integer.MAX_VALUE, 0);

    T left = traverse(root.left);
    T right = traverse(root.right);

    if (!left.isBST || !right.isBST)
      return new T(false, null, null, null);
    if (root.val <= left.mx || root.val >= right.mn)
      return new T(false, null, null, null);

    // The `root` is a valid BST.
    final int sum = root.val + left.sum + right.sum;
    ans = Math.max(ans, sum);
    return new T(true, Math.max(root.val, right.mx), Math.min(root.val, left.mn), sum);
  }
}
