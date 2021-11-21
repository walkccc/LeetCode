class Solution {
  public TreeNode constructFromPrePost(int[] pre, int[] post) {
    return helper(pre, post, 0, 0, pre.length);
  }

  // construct tree by pre[i..i + n) and post[j..j + n)
  private TreeNode helper(int[] pre, int[] post, int i, int j, int n) {
    if (n == 0)
      return null;

    TreeNode root = new TreeNode(pre[i]);
    if (n == 1)
      return root;

    int l = 1; // length of left subtree
    while (pre[i + 1] != post[j + l - 1])
      ++l;

    root.left = helper(pre, post, i + 1, j, l);
    root.right = helper(pre, post, i + 1 + l, j + l, n - 1 - l);

    return root;
  }
}
