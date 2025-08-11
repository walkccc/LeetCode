class T {
  public int inc; // the length of longest incrementing branch
  public int dec; // the length of longest decrementing branch

  public T(int inc, int dec) {
    this.inc = inc;
    this.dec = dec;
  }
}

class Solution {
  public int longestConsecutive(TreeNode root) {
    longestPath(root);
    return ans;
  }

  private int ans = 0;

  private T longestPath(TreeNode root) {
    if (root == null)
      return new T(0, 0);

    int inc = 1;
    int dec = 1;

    if (root.left != null) {
      T l = longestPath(root.left);
      if (root.val + 1 == root.left.val)
        inc = l.inc + 1;
      else if (root.val - 1 == root.left.val)
        dec = l.dec + 1;
    }

    if (root.right != null) {
      T r = longestPath(root.right);
      if (root.val + 1 == root.right.val)
        inc = Math.max(inc, r.inc + 1);
      else if (root.val - 1 == root.right.val)
        dec = Math.max(dec, r.dec + 1);
    }

    ans = Math.max(ans, inc + dec - 1);
    return new T(inc, dec);
  }
}
